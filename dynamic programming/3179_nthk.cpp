class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = 1e9 + 7;
        vector<int> dp(n, 1);
        for (int i = 0; i < k; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
        return dp[n - 1];
    }
};