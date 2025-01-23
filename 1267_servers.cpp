class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        vector<bool> rows(m), cols(n);
    
        for (int i = 0; i < m; ++i) {
            int row = 0;
            for (int j = 0; j < n; ++j) {
                row += grid[i][j];
            }
            if (row > 1) {
                res += row;
                rows[i] = true;
            }
        }

        for (int j = 0; j < n; ++j) {
            int col = 0;
            for (int i = 0; i < m; ++i) {
                col += grid[i][j];
            }
            if (col > 1) {
                res += col;
                cols[j] = true;
            }
        }

        // intersection
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && rows[i] && cols[j]) --res;
            }
        }

        return res;
    }
};
