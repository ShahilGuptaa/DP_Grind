#include<bits/stdc++.h>
using namespace std;

int n;
string a;
vector<vector<int>> dp;

//aa
//Print all (i,j), st, a[i..j] is a pelindrome
int rec(int i, int j) //if [i..j] is a pelindrome or not
{
    if(i>=j) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==a[j]){
        return dp[i][j] = rec(i+1,j-1);
    }else{
        return dp[i][j] = 0;
    }
}
int main()
{
    cin>>a;
    n = a.size();
    dp.assign(n,vector<int>(n,-1));

    //TC: Armotized O(N^2)
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(rec(i,j)){
                cout<<i<<" "<<j<<"\n";
            }
        }
    }
}