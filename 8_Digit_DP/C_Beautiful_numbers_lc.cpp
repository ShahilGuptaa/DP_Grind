#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/description/
class Solution {
    string l, r;
    int k;
    int dp[12][20][12][12][2][2][2];

public:
    int rec(int ind, int sum, int evens, int odds, int lt, int ht, int lz) {
        if (ind == (int)r.size())
            return (sum == 0 && evens == odds);

        int &res = dp[ind][sum][evens][odds][lt][ht][lz];
        if (res != -1) return res;

        res = 0;
        int lo = 0, hi = 9;
        if (lt) lo = l[ind] - '0';
        if (ht) hi = r[ind] - '0';

        for (int i = lo; i <= hi; i++) {
            int nlt = lt, nht = ht, nlz = lz;
            if (i != lo) nlt = 0;
            if (i != hi) nht = 0;
            if (i != 0) nlz = 0;

            if (nlz) {
                res += rec(ind + 1, (10 * sum + i) % k,
                           evens, odds, nlt, nht, nlz);
            } else {
                res += rec(ind + 1, (10 * sum + i) % k,
                           evens + (i % 2 == 0),
                           odds + (i % 2 == 1),
                           nlt, nht, nlz);
            }
        }
        return res;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        l = to_string(low);
        r = to_string(high);
        this->k = k;

        int pad = r.size() - l.size();
        l = string(pad, '0') + l;

        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, 0, 1, 1, 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int low, high, k;
    cin >> low >> high >> k;

    Solution sol;
    cout << sol.numberOfBeautifulIntegers(low, high, k) << "\n";

    return 0;
}
