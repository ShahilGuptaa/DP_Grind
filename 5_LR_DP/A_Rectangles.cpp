//https://cses.fi/problemset/task/1744

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

//dp[a][b] = dp[b][a];
int rec(int a, int b)
{
    if(a==b) return 0;
    if(dp[a][b]!=-1) return dp[a][b];

    //Transitions
    int ans = 1e9;
    //Cutting the side of b
    for(int x=1;x<b;x++){
        ans = min(ans, 1 + rec(a,x) + rec(a,b-x));
    }
    //cutting the side of a
    for(int y=1;y<a;y++){
        ans = min(ans, 1 + rec(y,b) + rec(a-y,b));
    }
    return dp[a][b] = ans;
}

int main()
{
    int a, b; cin>>a>>b;
    dp.assign(a+1,vector<int>(b+1,-1));
    cout<<rec(a,b)<<'\n';
}