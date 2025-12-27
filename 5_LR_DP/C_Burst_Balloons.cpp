#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> dp;
public:
    int rec(int l, int r, vector<int>& nums) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        int left = (l - 1 >= 0) ? nums[l - 1] : 1;
        int right = (r + 1 < (int)nums.size()) ? nums[r + 1] : 1;

        for (int i = l; i <= r; i++) {
            ans = max(ans, rec(l, i - 1, nums) + rec(i + 1, r, nums) + (nums[i] * left * right));
        }
        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return 0;
        dp.assign(n, vector<int>(n, -1));
        return rec(0, n - 1, nums);
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<int> nums = {3, 1, 5, 8};
    
    int result = sol.maxCoins(nums);
    
    cout << "Maximum coins: " << result << endl;

    return 0;
}