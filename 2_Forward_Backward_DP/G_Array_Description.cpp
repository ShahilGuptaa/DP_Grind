#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int mod = 1000000007;
/*
3 5
3 0 2

3 2 2 return 1
3 3 2 return 1
3 4 2 return 0
*/
int n,m;
vector<int> x;
vector<vector<int>> dp;

lli rec(int ind, int prev) //no of arrays with description followed starting from ind
{
    if(ind==n) return 1;
    if(x[ind] && ind!=0 && abs(prev - x[ind])>1) return 0;

    if(dp[ind][prev]!=-1) return dp[ind][prev];

    if(x[ind]!=0) return dp[ind][prev] = rec(ind+1,x[ind])%mod; 

    int l = 1,u = m;
    if(prev!=m+1){
        l = max(1,prev-1);
        u = min(m,prev+1);
    }
    lli ans = 0;
    for(int i=l;i<=u;i++){
        ans += rec(ind+1,i);
        ans%=mod;
    }
    return dp[ind][prev] = ans;
}

int main()
{
    cin>>n>>m;
    x.resize(n);
    for(int i=0;i<n;i++) cin>>x[i];
    dp.assign(n,vector<int>(m+2,-1));

    cout<<rec(0,m+1)<<'\n';
}