#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;

    cin>>n>>x;

    int arr[2*n];

    for(int i=0;i<2*n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+2*n);

    bool ok = true;
    for (int i = 0; i < n;i++)
        if (arr[n + i] - arr[i] <= x) ok = false;
    cout << (ok ? "YES" : "NO") << "\n";


    return 0;


}
