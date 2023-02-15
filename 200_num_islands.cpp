class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // order MATTERS to check boundaries
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1' ) {
            return;
        }
        // mark node as visited
        grid[i][j] = '#';

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++islands;
                }
            }
        }
        return islands;
    }
};
