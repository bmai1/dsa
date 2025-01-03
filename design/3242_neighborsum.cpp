class NeighborSum {
public:
    vector<vector<int>> g;
    int n;
    NeighborSum(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
    }
    
    int adjacentSum(int value) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        return sum(dirs, value);
    }
    
    int diagonalSum(int value) {
        vector<pair<int, int>> dirs = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        return sum(dirs, value);
    }

    int sum(vector<pair<int, int>>& dirs, int value) {
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (g[row][col] == value) {
                    int sum = 0;
                    for (auto dir : dirs) {
                        int nrow = row + dir.first, ncol = col + dir.second;
                        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n) {
                            sum += g[nrow][ncol];
                        }
                    }
                    return sum;
                }
            }
        }
        return -1; 
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
