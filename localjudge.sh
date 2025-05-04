#!/bin/bash

usage() {
    echo "Usage: $0 -path <path_to_task_directory>"
    exit 1
}

while [[ $# -gt 0 ]]; do
    case "$1" in
        -path)
            shift
            if [[ -z "$1" ]]; then
                echo "$0: error: missing argument for '-path'"
                usage
            fi
            TASK_PATH="$1"
            shift
            ;;
        -*)
            echo "$0: error: unrecognized option '$1'"
            usage
            ;;
        *)
            echo "$0: error: unexpected argument '$1'"
            usage
            ;;
    esac
done

if [[ -z "$TASK_PATH" ]]; then
    echo "$0: error: missing required option '-path'"
    usage
fi

GREEN='\e[32m'
RED='\e[31m'
BOLDGREEN='\e[1;32m'
BOLDRED='\e[1;31m'
RESET='\e[0m'

TIME_LIMIT=$(grep 'time_limit' "$TASK_PATH"/limits.yaml | awk '{print $2}')
MEMORY_LIMIT=$(grep 'memory_limit' "$TASK_PATH"/limits.yaml | awk '{print $2}')

declare -A verdict_priority=(
    ["COMPILATION ERROR"]=4
    ["RUNTIME ERROR"]=3
    ["TIME/MEMORY LIMIT EXCEEDED"]=2
    ["WRONG ANSWER"]=1
    ["ACCEPTED"]=0
)

declare -a final_results

clean_file() {
    sed -e 's/[[:space:]]\+/ /g' \
        -e 's/^ *//' \
        -e 's/ *$//' \
        -e '/^$/d' "$1" \
    | awk '{print} END{if (NR > 0) print ""}' > "$2"
}

for source_file in "$TASK_PATH"/submission/*.cpp; do
    name=$(basename "$source_file" .cpp)
    executable="./$name.bin"

    echo "Judging $name..."

    g++ -O2 -std=c++17 "$source_file" -o "$executable" 2> "$name.compile.log" 2>/dev/null
    if [ $? -ne 0 ]; then
        echo "$name: COMPILATION ERROR"
        final_results+=("$name: ${BOLDRED}COMPILATION ERROR${RESET}")
        continue
    fi

    highest_verdict="ACCEPTED"

    shopt -s nullglob
    mapfile -t inputs < <(find "$TASK_PATH"/input -type f -name "input*.txt" | sort -V)

    for in_file in "${inputs[@]}"; do
        case_id=$(basename "$in_file" .txt | sed 's/input//')
        printf -v padded_case_id "%02d" "$case_id"

        ans_file="$TASK_PATH"/answer/answer${case_id}.txt
        output_file="output_file.txt"

        input_with_sentinel=input_with_sentinel.txt
        cp "$in_file" $input_with_sentinel
        echo -e "\n$RANDOM" >> "$input_with_sentinel"

        /usr/bin/timeout --preserve-status -s SIGKILL "${TIME_LIMIT}s" \
        /usr/bin/time -f "TIME=%e MEM=%M" -o usage.log \
        bash -c "ulimit -v $((MEMORY_LIMIT * 1024)); \"$executable\" < $input_with_sentinel > $output_file" 2>/dev/null

        status=$?
        read time_s mem_kb < <(awk -F '[ =]' '{print $2, $4}' usage.log 2>/dev/null)
        rm -f usage.log

        time_ms=$(echo "($time_s * 1000 + 0.5)/1" | bc)
        mem_mb=$(echo "($mem_kb / 1024 + 0.5)/1" | bc)

        if [ $status -eq 124 ]; then
            test_verdict="TIME/MEMORY LIMIT EXCEEDED"
        elif [ $status -eq 137 ]; then
            test_verdict="TIME/MEMORY LIMIT EXCEEDED"
        elif [ $status -ne 0 ]; then
            test_verdict="RUNTIME ERROR"
        else
            clean_file "$ans_file" ans_clean.txt
            clean_file "$output_file" output_clean.txt

            if ! diff -q output_clean.txt ans_clean.txt > /dev/null; then
                test_verdict="WRONG ANSWER"
            else
                test_verdict="ACCEPTED"
            fi

            rm -f output_clean.txt ans_clean.txt
        fi

        if [ "$test_verdict" = "ACCEPTED" ]; then
            echo -e "Test $padded_case_id: ${GREEN}ACCEPTED${RESET} [${time_ms}ms, ${mem_mb}MB]"
        else
            echo -e "Test $padded_case_id: ${RED}$test_verdict${RESET}"
        fi

        if [ ${verdict_priority[$test_verdict]} -gt ${verdict_priority[$highest_verdict]} ]; then
            highest_verdict="$test_verdict"
        fi
    done

    echo

    if [ "$highest_verdict" = "ACCEPTED" ]; then
        final_results+=("$name: ${BOLDGREEN}$highest_verdict${RESET}")
    else
        final_results+=("$name: ${BOLDRED}$highest_verdict${RESET}")
    fi

    rm -f "$executable" $input_with_sentinel $output_file "$name.compile.log"
done

echo
echo "================== FINAL VERDICTS =================="
for result in "${final_results[@]}"; do
    echo -e "$result"
done
echo
