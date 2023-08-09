class Solution {
public:
    int numTilings(int n) {
        if (n < 3) return n;
        if (n == 3) return 5;
        long long dp[n];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;
        for (int i = 3; i < n; ++i) {
            // most importantly is to solve for the dp recurrence formula
            // dp[i] = 2dp[i - 1] + dp[i - 3]
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % ((long long) pow(10, 9) + 7);
        }
        return dp[n - 1];
    }
};