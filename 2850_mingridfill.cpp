class Solution { 
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int z = 0;
        for (int i = 0; i < 3; ++i) 
            for (int j = 0; j < 3; ++j)
                if (!grid[i][j]) ++z;
        if (!z) return 0;
        
        int ans = INT_MAX;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (!grid[i][j])
                    for (int k = 0; k < 3; ++k) 
                        for (int l = 0; l < 3; ++l) {
                            int d = abs(k - i) + abs(l - j);
                            if (grid[k][l] > 1) {
                                grid[k][l]--;
                                grid[i][j]++;
                                // the meat 
                                ans = min(ans, d + minimumMoves(grid));
                                grid[k][l]++;
                                grid[i][j]--;
                            }
                        }
        return ans;
    }
};