class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // flatten grid
        int m = grid.size(), n = grid[0].size();
        vector<int> flat;
        for (auto r : grid) 
            for (auto c : r)
                flat.push_back(c);
    
        vector<vector<int>> ans(m, vector<int>(n));
        int t = flat.size(), i = t - (k % t);
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i == t) i = 0;
                ans[j][k] = flat[i++];
            }
        }
        return ans;
    }
};