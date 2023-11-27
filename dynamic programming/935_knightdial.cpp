class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    vector<vector<int>> dp;
    int f(int n, int curr) {
        if (n == 0) return 1;
        if (dp[n][curr] != -1) return dp[n][curr];
        int res = 0;
        for (auto neighbor : jumps[curr]) {
            res = (res + f(n - 1, neighbor)) % MOD;
        }
        dp[n][curr] = res;
        return res;
    }
public:
    int knightDialer(int n) {
        dp.resize(n + 1, vector<int>(10, -1));
        int total = 0;
        for (int i = 0; i <= 9; ++i) {
            total = (total + f(n - 1, i)) % MOD;
        }
        return total;
    }
};