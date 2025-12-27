#include<bits/stdc++.h>
using namespace std;

/*
A = (a*b)
B = (p*q)

AB is defined when b = p

A = (a*p)
B = (p*q)
Cost (Time complexity to multiply) = O(a*p*q)
*/

/*
 * MATRIX CHAIN MULTIPLICATION (MCM) PROBLEM
 * -----------------------------------------
 * Given a sequence of matrices, find the most efficient way to multiply them together. 
 * The problem is not to actually perform the multiplication, but to decide the order of multiplications (parenthesization).

 * Matrix multiplication is associative, so (A*B)*C = A*(B*C). 
 * However, the number of scalar multiplications differs:
 * * Example:
 * Matrix A: 10 x 100
 * Matrix B: 100 x 5
 * Matrix C: 5 x 50

 * 1. ((A*B)*C): (10*100*5) + (10*5*50) = 5,000 + 2,500 = 7,500 ops.
 * 2. (A*(B*C)): (100*5*50) + (10*100*50) = 25,000 + 50,000 = 75,000 ops.
 * Goal: Find the minimum cost (scalar multiplications) for a given chain.
*/

/*
N = 3;
10 100 5 50
mat[i] = arr[i]*arr[i+1] 
*/


int n;
vector<int> arr;
vector<vector<int>> dp;

//   l   i    r
//20 30 40 50 60 70
//   30*50 + 50*70

//Time Complexity = O(n^3)
//Space Complexity = O(n^2) for memoization
int rec(int l, int r)
{
    //Base case
    if(l>=r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    int ans = 1e9;
    for(int i=l;i<r;i++){
        ans = min(ans, rec(l,i) + rec(i+1,r) + (arr[l]*arr[i+1]*arr[r+1]));
    }
    return dp[l][r] = ans;
}


int main()
{
    cin>>n;
    arr.resize(n+1);
    dp.assign(n,vector<int>(n,-1));
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    cout<<rec(0,n-1)<<'\n';
    return 0;
}