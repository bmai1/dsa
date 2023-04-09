class Solution {
private: 
    int fall(vector<vector<int>>& grid, int row, int col) {
        // check walls
        if (col == 0 && grid[row][col] == -1) { return -1; }
        if (col == grid[0].size() - 1 && grid[row][col] == 1) { return -1; }
        
        // help me stepbro
        if (grid[row][col] == -1 && grid[row][col - 1] != -1) { return -1; }
        if (grid[row][col] == 1 && grid[row][col + 1] != 1) { return -1; }
        
        // drops out of high school
        if (row == grid.size() - 1) { return col + grid[row][col]; }
        return fall(grid, row + 1, col + grid[row][col]);
    }
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();  
        if (n == 1) { return {-1}; }
        vector<int> ans(n); 
        for (int col = 0; col < n; ++col) {
            ans[col] = fall(grid, 0, col);
        }
        return ans;  
    }
};
