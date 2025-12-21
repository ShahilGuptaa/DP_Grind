//https://cses.fi/problemset/task/1097
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int n; 
vector<lli> x;
vector<vector<lli>> dp;

lli rec(int l, int r) //maximum possible score for the first player
{
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    //whos turn is this?
    //elements left to be taken = (r-l+1)
    //taken elements = n - (r-l+1)
    
    int taken_elements = n - (r-l+1);
    lli ans = 0;
    if(taken_elements%2==0){ //1st player turn
        ans = max(x[l] + rec(l+1,r), x[r] + rec(l,r-1));
    }else{
        ans = min(rec(l+1,r), rec(l,r-1));
    }
    return dp[l][r] = ans;
}

int main()
{
    cin>>n;
    x.resize(n);
    for(int i=0;i<n;i++) cin>>x[i]; 
    dp.assign(n,vector<lli>(n,-1));    
    cout<<rec(0,n-1)<<'\n';   
}