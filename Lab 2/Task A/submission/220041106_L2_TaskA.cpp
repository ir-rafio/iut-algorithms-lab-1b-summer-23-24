#include<bits/stdc++.h>
using namespace std;

int container(int n,int x, vector<int>&ar){
    sort( ar.begin(),ar.end());
    int count = 0;
    for(int i=n-1;i>=0 && x >= 0 ;i--){
        if(ar[i]<=x){
            x -= ar[i];
            count ++;
        }
    }
    return x==0? count : -1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        vector<int>ar(n);
        for(int i=0;i<n;i++){
            cin >> ar[i];
        }
        cout << container(n,x,ar) << "\n";
        
    }
    return 0;
}