#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>start(n),end(n);
        for(int i=0;i<n;i++){
            cin>>start[i];
        }

        for(int i=0 ; i<n ; i++){
            cin>>end[i];
        }

        vector<pair<int,int>>acts;

        for(int i=0;i<n;i++){
            acts.push_back({end[i],start[i]});
        }

        sort(acts.begin(),acts.end());

        int c=0;
        int lastendtask=0;

        for(int i=0;i<n;i++){
            int starttask=acts[i].second;
            int endtask=acts[i].first;

            if(starttask>=lastendtask){
                c++;
                lastendtask=endtask;
            }

        }

        cout<<c<<endl;
    }
}
