class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int r(int n, int k, int target, int total) {
        if (n > target || n < 0 || total > target) return 0;
        if (n == 0 && total == target) return 1;
        if (dp[n][total] != -1) return dp[n][total];
        int curr = 0;
        for (int i = 1; i <= k; ++i) {
            curr = curr % mod + r(n - 1, k, target, total + i) % mod;
        }
        return dp[n][total] = curr % mod;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n + 1, vector<int>(target + k, -1));
        return r(n, k, target, 0);
    }
};