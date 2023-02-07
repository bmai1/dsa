class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // grid[i][j] can't be higher than the maximum of its row nor the maximum of its col
        // max increasing height is min(row[i], col[j]) - grid[i][j]
        int n = grid.size();
        vector<int> row(n, 0), col(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += min(row[i], col[j]) - grid[i][j];
            }
        }
        return ans; 
    }
};
