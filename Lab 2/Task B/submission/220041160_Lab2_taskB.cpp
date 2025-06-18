#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,x;

    cin>>n>>x;

    vector<int> a(2*n);

    for(int i=0;i<2*n;i++){
        cin>>a[i];
        }

        sort(a.begin(),a.end());

        bool canArrange =true;

        for(int i=0;i<n;i++){
            if(a[n+i]<a[i]+x){
                canArrange=false;
                break;
                }

            }

        if(canArrange){
            cout<<"YES\n";
            }

        else
            cout<<"NO\n";

            }
