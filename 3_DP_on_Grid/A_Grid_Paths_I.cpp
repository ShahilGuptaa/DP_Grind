/*
Consider an n x n grid whose squares may have traps. It is not allowed to move to a square with a trap.
Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.

(0,0) (n-1,m-1)

(i,j) -> (i+1,j) || (i,j+1)

*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> grid;
vector<vector<int>> dp;

int rec(int i, int j) //no. of ways to go from (i,j) to (n-1,m-1)
{
    if(i==n-1 && j==m-1) return 1;
    if(i>=n || j>=m) return 0;
    if(grid[i][j]=='*') return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = rec(i+1,j) + rec(i,j+1);
    return dp[i][j] = ans;
}

int main()
{
    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    dp.assign(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]=='*' || grid[n-1][m-1]=='*') cout<<"0\n";
    else cout<<rec(0,0)<<'\n';
}