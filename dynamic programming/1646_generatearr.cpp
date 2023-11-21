class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            // odd index:  dp[2 * i + 1] = dp[i] + dp[i + 1]
            if (i % 2) dp[i] = dp[(i - 1) / 2] + dp[1 + (i - 1) / 2];
            // even index: dp[2 * i] = nums[i]
            else dp[i] = dp[i / 2];
            res = max(res, dp[i]);
        }
        return res;
    }
};