class Solution {
private:
    int m, n;
    vector<pair<int, int>> dir = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int row, int col, int prev) {
        int mx = 1;
        for (auto d : dir) {
            int nrow = row + d.first, ncol = col + d.second;
            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && matrix[nrow][ncol] > prev) {
                if (!dp[nrow][ncol]) {
                    dp[nrow][ncol] = 1 + dfs(matrix, nrow, ncol, matrix[nrow][ncol]);
                }
                mx = max(mx, dp[nrow][ncol]);
            }
        }
        return mx; 
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        dp.resize(m, vector<int>(n));
        int ans = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, i, j, matrix[i][j]));
            }
        }
        return ans;
    }
};