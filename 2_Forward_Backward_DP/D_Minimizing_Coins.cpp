#include<bits/stdc++.h>
using namespace std;

int INF= 1e9+7;
vector<int> dp;

int rec(int target, vector<int> &c)
{
    int n = c.size();
    //Base case
    if(target==0) return 0;

    //Pruning
    if(target<0) return INF;

    if(dp[target]!=-1) return dp[target];

    int ans = INF;
    for(int i=0;i<n;i++){
        ans = min(ans, rec(target-c[i], c) + 1);
    }
    return dp[target] = ans;
}

int main()
{
    int n, x; cin>>n>>x;
    dp.assign(x+1,-1);
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];

    int ans = rec(x,c);
    if(ans>=INF) cout<<-1<<'\n'; 
    else cout<<ans<<'\n';

    return 0;
}