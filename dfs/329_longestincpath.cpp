class Solution {
private:
    int m, n, ans;
    vector<pair<int, int>> dir = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int row, int col) {
        if (dp[row][col]) return dp[row][col];
        dp[row][col] = 1;
        for (auto& d : dir) {
            int nrow = row + d.first, ncol = col + d.second;
            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && matrix[row][col] < matrix[nrow][ncol]) {
                dp[row][col] = max(dp[row][col], 1 + dfs(matrix, nrow, ncol));
            }
        }
        return dp[row][col];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ans = 1, m = matrix.size(), n = matrix[0].size();
        dp.resize(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};