class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), score = 0;
    
        // flip first col bit if 0
        for (auto& r : grid) {
            if (!r[0]) {
                for (auto& c : r) {
                    if (!c) c = 1;
                    else c = 0;
                }
            }
        }

        // flip whole col if more zeroes 
        for (int c = 0; c < n; ++c) {
            int z = 0;
            for (int r = 0; r < m; ++r) {
                z += !grid[r][c];
            }
            if (z > m - z) {
                for (auto& r : grid) {
                    if (!r[c]) r[c] = 1;
                    else r[c] = 0;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // cout << grid[i][j] << ' ';
                score += grid[i][j] * pow(2, n - j - 1);
            }
            // cout << endl;
        }
        
        return score;
    }
};