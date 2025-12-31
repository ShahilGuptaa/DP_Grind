//https://cses.fi/problemset/task/2220

#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

string a,b; 
lli dp[20][11][2][2];

//0_(lo-hi)

lli rec(int ind, int prev, int lt, int ht) //[ind...] no. of numbers
{
    //base case
    if(ind==b.size()) return 1;
    
    //memo
    if(dp[ind][prev][lt][ht]!=-1) return dp[ind][prev][lt][ht];

    //transitions
    int lo = 0, hi = 9;
    if(lt) lo = a[ind]-'0';
    if(ht) hi = b[ind]-'0';

    lli ans = 0;
    for(int i=lo;i<=hi;i++){
        int nlt = lt, nht = ht;
        if(i!=lo) nlt = 0;
        if(i!=hi) nht = 0;

        int nprev = i;
        if(prev==10 && i==0) nprev = 10;
        if(prev!=i) ans += rec(ind+1,nprev,nlt,nht);
    }
    return dp[ind][prev][lt][ht] = ans;
}

int main()
{
    cin>>a>>b;
    //padding leading zeros to a
    int cnt0s = b.size() - a.size();
    string s(cnt0s, '0');
    a = (s+a);

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,10,1,1)<<'\n';
}