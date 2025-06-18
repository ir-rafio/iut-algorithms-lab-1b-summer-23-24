#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;

while(t--){
   int n;
   long long x;
   cin>>n >>x;

   vector< long long> a(n);
   for (int i = 0; i < n; i++) {
            cin >> a[i];
}
    sort(a. begin(),a.end(), greater <long long>());

    long long collected= 0;
    int used = 0;

    for (long time :a ){
        if (collected>=x) break;
        collected += a;
            used++;
    }
    if (collected >= x) {
            cout << used << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
