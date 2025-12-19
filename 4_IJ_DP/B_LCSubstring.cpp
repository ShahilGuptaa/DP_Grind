#include<bits/stdc++.h>
using namespace std;

int n,m;
string a,b;
vector<vector<int>> dp;

int rec(int i, int j) //[i...n-1], [j...m-1] -> LCSubstring starting at i and j
{
    if(i==n || j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j] = 1 + rec(i+1,j+1);
    else return dp[i][j] = 0;
}
int main()
{
    cin>>a>>b;
    n = a.size(); m = b.size();
    dp.assign(n,vector<int>(m,-1));
    int ans = 0;

    //Time Complexity: Armotized O(n*m)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(ans, rec(i,j));
        }
    }
    cout<<ans<<'\n';
}