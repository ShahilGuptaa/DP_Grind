//https://atcoder.jp/contests/dp/tasks/dp_s

#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
/*
l <= _ _ _ _ _ _ _ _ _ .... _ <= r
lo = 0
hi = 9

lt, ht
l = 00234
    1_
r = 22345

2 _(lt = 0, ht = 1)

lt = 1, ht = 1
_(0-2)
0 -> (nlt = 1, nht = 0)
0 0 _(2-9)-> (nlt = 1, nht = 0)
0 0 2 => (nlt = 1, nht = 0)
0 0 3 _(0-9) -> (nlt = 0, nht = 0)


l = 32345
r = 76890

lt = 1, ht = 1
_ (3-7)
*/

string l,r; 
int d;
const int mod = 1000000007;
int dp[10010][100][2][2];

//O(len(r) * (sum) * 2*2*10) 10 is for loop inside
//O(10^4 * 10^2 * 40)
lli rec(int ind, int sum, int lt, int ht) //[ind...] no. of numbers
{
    //base case
    if(ind==r.size()) return (sum==0);
    
    //memo
    if(dp[ind][sum][lt][ht]!=-1) return dp[ind][sum][lt][ht];

    //transitions
    int lo = 0, hi = 9;
    if(lt) lo = l[ind]-'0';
    if(ht) hi = r[ind]-'0';

    lli ans = 0;
    for(int i=lo;i<=hi;i++){
        int nlt = lt, nht = ht;
        if(i!=lo) nlt = 0;
        if(i!=hi) nht = 0;

        int nsum = (sum+i)%d;
        ans += rec(ind+1,nsum,nlt,nht);
        ans%=mod;
    }
    return dp[ind][sum][lt][ht] = ans;
}

int main()
{
    l = "1";
    cin>>r;
    cin>>d;
    //padding leading zeros to l
    int cnt0s = r.size() - l.size();
    string s(cnt0s, '0');
    l = (s+l);

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,1,1)<<'\n';
}