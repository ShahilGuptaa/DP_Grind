#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
/*
Capacity

val[]
weight[]

Total_wt <= cap, st, total_val should be maximized
*/

/*

n stocks
present_val[]:
expected_future_val[]:

ith stock - (expected_future_val[i] - present_val[i])
we can buy almost k stocks, also there is a cooldown of k day

total_amount_initially - amt
(m stocks -> sum(present_val[i]) <= amt)

What is the maximum profit that we can get

eg:
amt = 100
k = 3
cooldown = 1

present[] = {10, 20, 30, 50, 20, 10, 100}
final[] = {30, 100, 10, 10, 10 , 50, 1000}

Answer: 900
*/

//Forward DP
class solution{
    int limit, cd;
    vector<vector<vector<lli>>> dp;
    //i- current index, taken - taken till i-1
    lli rec(int i, int taken, int val_left, vector<int> &pre, vector<int> &fin) //returns (i,....,n) maximum profit
    {
        int n = pre.size();
        if(i>=n) return 0;
        if(taken>=limit) return 0;

        //memoize
        if(dp[i][taken][val_left]!=-1) return dp[i][taken][val_left];

        lli ans = 0;
        lli nt = rec(i+1, taken, val_left, pre, fin);
        lli tt = 0;
        if(val_left >= pre[i]) tt = (fin[i] - pre[i]) + rec(i+1+cd, taken+1, val_left - pre[i], pre, fin);
        ans = max(nt,tt);

        return dp[i][taken][val_left] = ans;
    }
public:
    lli maximize_profit(int amt, int cooldown, int k, vector<int> &pre, vector<int> &fin)
    {
        int n = pre.size();
        cd = cooldown;
        limit = k;
        dp.assign(n,vector<vector<lli>>(k+1,vector<lli>(amt+1,-1)));

        lli ans = rec(0,0,amt,pre,fin);
        return ans;
    }
};

int main()
{
    int n,amt,cooldown,k; 
    cin>>n>>amt>>cooldown>>k;
    vector<int> pre(n), fin(n);
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>fin[i];

    solution obj;
    cout<<obj.maximize_profit(amt,cooldown,k,pre,fin)<<'\n';

    return 0;
}

/*
    lli rec(int i, int taken, int val_left, vector<int> &pre, vector<int> &fin) //returns (i,....,n) maximum profit
    {
        int n = pre.size();
        if(i==n) return 0;
        if(taken>=limit) return 0;

        //memoize

        lli ans = rec(i+1, taken, val_left, pre, fin);
        if(val_left >= pre[i]) ans = max(ans, (fin[i] - pre[i]) + rec(i+1+cd, taken+1, val_left - pre[i], pre, fin));
        return ans;
    }
*/