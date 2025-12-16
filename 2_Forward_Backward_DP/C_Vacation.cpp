#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

/*
Taro will choose one of the following activities and do it on the 
i-th day:

A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.
*/

vector<vector<int>> dp;

//prev = (0/1/2/3)
int rec(int i, int prev, vector<vector<int>> &act) // maximum value (i,...,n) 
{
    int n = act[0].size();
    if(i>=n) return 0;
    
    if(dp[i][prev]!=-1) return dp[i][prev];

    int ans = 0;
    for(int cur=0;cur<3;cur++) //cur-> current activity
    {
        if(cur!=prev) ans = max(ans, rec(i+1,cur,act) + act[cur][i]);
    }
    return dp[i][prev] = ans;
}

int main()
{
    int n; cin>>n;
    vector<vector<int>> act(3,vector<int>(n));
    for(int i=0;i<n;i++){
        cin>>act[0][i]>>act[1][i]>>act[2][i];
    }
    dp.assign(n+1,vector<int>(4,-1));

    cout<<rec(0,3,act)<<'\n';

    return 0;
}