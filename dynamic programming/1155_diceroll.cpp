class Solution {
private:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int r(int n, int k, int target, int total) {
        if (n == 0) return total == target;
        if (total > target) return 0;
        if (dp[n][total] != -1) return dp[n][total];
        int res = 0;
        for (int i = 1; i <= k; ++i) {
            res = (res + r(n - 1, k, target, total + i)) % mod;
        }
        return dp[n][total] = res;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n + 1, vector<int>(target + k, -1));
        return r(n, k, target, 0);
    }
};