#include<bits/stdc++.h>
using namespace std;

int n,m;
string a,b;
vector<vector<int>> dp;

int rec(int i, int j) //[i...n-1], [j...m-1] -> LCSubsequ
{
    if(i==n || j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j] = 1 + rec(i+1,j+1);
    else return dp[i][j] = max(rec(i+1,j), rec(i,j+1));
}
int main()
{
    cin>>a>>b;
    n = a.size(); m = b.size();
    dp.assign(n,vector<int>(m,-1));
    cout<<rec(0,0)<<'\n';
}