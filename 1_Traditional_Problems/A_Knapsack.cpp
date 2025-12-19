#include<bits/stdc++.h>
using namespace std;
using lli = long long;
//https://atcoder.jp/contests/dp/tasks/dp_e

int n, cap;
vector<lli> w,v;
vector<vector<lli>> dp;

//Time = Space = O(n * cap)
lli rec(int ind, int cap_left) //return max value that can be taken from [ind....n-1] with currrent cap = cap_left
{
    if(ind==n) return 0;
    if(dp[ind][cap_left]!=-1) return dp[ind][cap_left];

    lli ans = rec(ind+1,cap_left);
    if(w[ind]<=cap_left) ans = max(ans, v[ind] + rec(ind+1, cap_left - w[ind]));

    return dp[ind][cap_left] = ans;
}

int main()
{
    cin>>n>>cap;
    w.resize(n); v.resize(n);
    dp.assign(n, vector<lli>(cap+1,-1));
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    cout<<rec(0,cap)<<'\n';
}