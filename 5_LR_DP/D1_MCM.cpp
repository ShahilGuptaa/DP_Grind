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

//   0    1      2     3    4
//(20*30 30*40) (40*50 50*20 20*100)
//20*40 40*100
//20*40*100
//mat[l].first * mat[i].second * mat[r].second


int n;
vector<pair<int,int>> mat;
vector<vector<int>> dp;
int rec(int l, int r)
{
    //Base case
    if(l>=r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    int ans = 1e9;
    for(int i=l;i<r;i++){
        ans = min(ans, rec(l,i) + rec(i+1,r) + (mat[l].first * mat[i].second * mat[r].second));
    }
    return dp[l][r] = ans;
}

int main()
{
    cin>>n;
    mat.resize(n);
    dp.assign(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        cin>>mat[i].first>>mat[i].second;
    }
    for(int i=1;i<n;i++){
        if(mat[i].first!=mat[i-1].second){
            cout<<"Multiplication not possible";
            return 0;
        }
    }
    cout<<rec(0,n-1)<<'\n';
    return 0;
}