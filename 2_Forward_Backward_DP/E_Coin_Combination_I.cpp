#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int rec(int target, vector<int> &c)
{
    int n = c.size();
    if(target==0) return 1;

    if(dp[target]!=-1) return dp[target];

    int ans = 0;
    for(int i=0;i<n;i++){
        if(target >= c[i]){
            ans += rec(target - c[i], c);
        }
    }
    return dp[target] = ans;
}

int main()
{
    int n, x; cin>>n>>x;
    dp.assign(x+1,-1);
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];

    int ans = rec(x,c);
    cout<<ans<<'\n';

    return 0;
}