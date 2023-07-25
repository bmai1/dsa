class Solution {
private: 
    int p = 0;
    void dfs(vector<vector<int>>&grid, int i, int j) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] == 0) {
            ++p;
            return; 
        }
        if (grid[i][j] == -1) return;
        grid[i][j] = -1; 
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) 
            for (int j = 0; j < grid[0].size(); ++j) 
                if (grid[i][j] == 1) dfs(grid, i, j);
        return p; 

        int p = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    if (i == 0                  || !grid[i - 1][j]) ++p; // check row above
                    if (i == grid.size() - 1    || !grid[i + 1][j]) ++p; // check row below
                    if (j == 0                  || !grid[i][j - 1]) ++p; // check col left
                    if (j == grid[0].size() - 1 || !grid[i][j + 1]) ++p; // check col right
                }
            }
        }
        return p;

        int count = 0, repeat = 0; 
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    ++count;
                    if (i != 0 && grid[i - 1][j] == 1) ++repeat;
                    if (j != 0 && grid[i][j - 1] == 1) ++repeat;
                }
            }
        }
        return 4 * count - 2 * repeat;
    }
};