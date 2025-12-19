#include<bits/stdc++.h>
using namespace std;
using lli = long long;
//https://atcoder.jp/contests/dp/tasks/dp_e

int n, cap;
vector<lli> w,v;
vector<vector<lli>> dp;
int INF = 1e9+100;

//total value that can be taken is between 1 to 10^5
lli rec(int ind, int value_left) //returns minimum cap required to make this value_left
{
    if(value_left==0) return 0;
    if(ind==n) return INF;

    if(dp[ind][value_left]!=-1) return dp[ind][value_left];

    lli ans = rec(ind+1, value_left);
    if(v[ind]<=value_left) ans = min(ans, w[ind] + rec(ind+1, value_left-v[ind]));

    return dp[ind][value_left] = ans;
}

int main()
{
    cin>>n>>cap;
    w.resize(n); v.resize(n);

    lli total = 0;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
        total += v[i];
    }
    dp.assign(n,vector<lli>(total+1,-1));
    lli ans = 0;
    for(int val=1; val<=total; val++)
    {
        lli cap_req = rec(0,val);
        if(cap >= cap_req) ans = val;
    }
    cout<<ans<<'\n';
    return 0;
}