class Solution {

private: 
    void dfs(vector<vector<int>>& grid, int i, int j) {
        // boundaries
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1) { return; }
        if (grid[i][j] != 1) { return; } // uncrossable cells

        // mark visited
        grid[i][j] = -1; 

        // visit surrounding nodes
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // start from edges
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                    dfs(grid, i, j);
                }
            }
        }

        // count remaining land cells
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) { ++ans; }
            }
        }
        return ans;
    }
};
