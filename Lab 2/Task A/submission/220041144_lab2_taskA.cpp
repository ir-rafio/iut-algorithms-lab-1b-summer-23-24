#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int>ar(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
sort (ar.rbegin(),ar.rend());
int cnt =0;
for (int i=0;i<n && x>0;i++)
{
    
    int take = min(x,ar[i]);
        x-=take;
        cnt++;
    
}  
if(x==0)
cout<<cnt<<endl;
else cout<<-1<<endl;      
}    
}