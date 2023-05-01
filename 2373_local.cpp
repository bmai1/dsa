class Solution {
private:
    void maxL(vector<vector<int>> &grid, int i, int j, int &m) {
        int n = grid.size();
        if (i > n - 1 || i < 0 || j > n - 1 || j < 0) { return; }
        m = max(m, grid[i][j]);
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 1; i <= n - 2; ++i) {
            for (int j = 1; j <= n - 2; ++j) {
                int m = 0;
                maxL(grid, i - 1, j - 1, m);
                maxL(grid, i - 1, j, m);
                maxL(grid, i - 1, j + 1, m);
                maxL(grid, i, j - 1, m);
                maxL(grid, i, j, m);
                maxL(grid, i, j + 1, m);  
                maxL(grid, i + 1, j - 1, m);
                maxL(grid, i + 1, j, m);
                maxL(grid, i + 1, j + 1, m);
                ans[i - 1][j - 1] = m;
            }
        }
        return ans;
    }
};
