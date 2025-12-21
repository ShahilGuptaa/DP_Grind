#include<bits/stdc++.h>
using namespace std;

int n,m;
string a,b;
vector<vector<int>> dp;

int rec(int i, int j) //[i...n-1], [j...m-1] -> min moves to make them same
{
    //Base case
    if(i==n) return (m-j); //insert this much elements in a
    if(j==m) return (n-i); //delete this no. of elements in a

    if(dp[i][j]!=-1) return dp[i][j];

    //Transitions
    int ans = 0;
    if(a[i]==b[j]) ans = rec(i+1,j+1);
    else{
        ans = min({1+rec(i+1,j+1), 1 + rec(i,j+1), 1 + rec(i+1,j)});
    }
    return dp[i][j] = ans;
}
int main()
{
    cin>>a>>b;
    n = a.size(); m = b.size();
    dp.assign(n,vector<int>(m,-1));
    cout<<rec(0,0)<<'\n';
}