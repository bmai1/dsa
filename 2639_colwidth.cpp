class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = grid[i][j], size = tmp <= 0 ? 1 : 0;
                while (tmp) { ++size; tmp /= 10; }
                ans[j] = max(ans[j], size); 
            }
        }
        return ans;
    }
};