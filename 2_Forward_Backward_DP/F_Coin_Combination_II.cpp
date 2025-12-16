#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int rec(int idx, int target, vector<int> &c)
{
    int n = c.size();
    if(target==0) return 1;
    if(idx==n) return 0; 

    if(dp[idx][target]!=-1) return dp[idx][target];

    int ans = 0;
    //not taken
    ans += rec(idx+1, target, c);
    if(c[idx]<=target) ans += rec(idx, target-c[idx],c);

    return dp[idx][target] = ans;
}

int main()
{
    int n, x; cin>>n>>x;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    dp.assign(n,vector<int>(x+1,-1));

    cout<<rec(0,x,c)<<'\n';

    return 0;
}