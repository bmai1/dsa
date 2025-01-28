class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || !grid[i][j]) return 0;
        int fish = grid[i][j];
        grid[i][j] = 0;
        return fish + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};
