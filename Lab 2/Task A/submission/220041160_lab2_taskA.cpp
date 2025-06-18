#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;

        vector<int> a(n);

        for(int i=0;i<n;i++){
            cin >> a[i];
            }

        sort(a.rbegin(),a.rend());


        int sum=0,count=0;

        for(int val : a){
        if(sum>=x)break;
            sum+=val;
            count++;
            }


        if(sum>=x)
            cout<<count<<"\n";

        else
            cout<<"-1\n";
            }
            }
