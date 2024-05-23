class Solution {
private:
    int re(vector<vector<int>>& grid, int i, int j, int prev, int score) {
        int m = grid.size(), n = grid[0].size();
        if (i == m || j == n) return INT_MIN;
        
        if (prev != INT_MIN) score += grid[i][j] - prev;
        
        int down = re(grid, i + 1, j, grid[i][j], score);
        int right = re(grid, i, j + 1, grid[i][j], score);
    
        if (prev == INT_MIN) return max(down, right);
        return max(score, max(down, right));
    }
public:
    int maxScore(vector<vector<int>>& grid) {
        int mx = INT_MIN;
        int m = grid.size(), n = grid[0].size();
    
        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // mx = max(mx, re(grid, i, j, INT_MIN, 0));
                if (j > 0) dp[j] = min(dp[j], dp[j - 1]);
                mx = max(mx, grid[i][j] - dp[j]);
                dp[j] = min(dp[j], grid[i][j]);
            }
        }
        return mx;
    }
};