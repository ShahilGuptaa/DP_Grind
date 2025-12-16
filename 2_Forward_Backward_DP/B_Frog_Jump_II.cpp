#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

/*
Problem Statement
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi

There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

If the frog is currently on Stone i, jump to one of the following: 
Stone i+1,i+2,…,i+K. Here, a cost of 
∣hi −hj∣ is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints
All values in input are integers.
2 ≤ N ≤ 10^5
1 ≤ K ≤ 100
1 ≤ hi ≤ 10^4
*/
//0 1 2 3 4
int INF = 1e9 + 7;

int rec(int i, int &k, vector<int> &h, vector<int> &dp) //minimum total cost from (i...n)
{
    int n = h.size();
    if(i==n-1) return 0;

    if(dp[i]!=-1) return dp[i];

    int ans = INF;
    for(int j=1;j<=k;j++){
        if(i+j<n) ans = min(ans, rec(i+j,k,h,dp) + abs(h[i+j] - h[i]));
    }
    return dp[i] = ans;
}

int main()
{
    int n,k; 
    cin>>n>>k;
    vector<int> height(n);
    for(int i=0;i<n;i++) cin>>height[i];

    vector<int> dp(n,-1);

    cout<<rec(0,k,height,dp);

    return 0;
}