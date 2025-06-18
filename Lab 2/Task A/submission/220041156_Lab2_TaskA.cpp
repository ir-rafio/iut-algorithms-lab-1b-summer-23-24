#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--) {
        int n,x;
        cin >>n>>x;

        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr,arr+n,greater<int>());

        int sum=0;
        int count=0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            count++;
            if(sum >= x) {
                break;
            }
        }

        if(sum >= x) {
            cout << count << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
