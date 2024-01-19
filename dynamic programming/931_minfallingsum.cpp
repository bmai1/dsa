class Solution {
private:
    int n;
    vector<vector<int>> dp;
    int re(vector<vector<int>>& matrix, int row, int col) {
        if (row == n - 1 && col >= 0 && col < n) return matrix[row][col];
        if (col >= n || col < 0) return INT_MAX;
        if (dp[row][col] != INT_MAX) return dp[row][col];

        int left = re(matrix, row + 1, col - 1);
        int down = re(matrix, row + 1, col);
        int right = re(matrix, row + 1, col + 1);

        int mn = min(left, min(down, right));
        return dp[row][col] = matrix[row][col] + mn;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        // can't init to be zero because sum can be zero.
        dp.resize(n + 1, vector<int>(n + 1, INT_MAX));

        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            res = min(res, re(matrix, 0, i));
        }

        return res;

        // vector<vector<int>> dp = matrix;
        // for (int i = n - 2; i >= 0; --i) {
        //     for (int j = 0; j < n; ++j) {
        //         int l = dp[i + 1][max(0, j - 1)];
        //         int d = dp[i + 1][j];
        //         int r = dp[i + 1][min(n - 1, j + 1)];
        //         dp[i][j] += min(l, min(d, r));
        //     }
        // }
        // return *min_element(dp[0].begin(), dp[0].end());
    }
};