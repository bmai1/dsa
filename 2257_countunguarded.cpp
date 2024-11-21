/* class Solution {
private:
    void see(vector<vector<int>>& grid, pair<int, int>& dir, int i, int j) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] == -1) return;
        grid[i][j] = 1; 
        see(grid, dir, i + dir.first, j + dir.second);
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        vector<pair<int, int>> dir = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };

        for (auto wall : walls) {
            grid[wall[0]][wall[1]] = -1;
        }
        
        for (auto guard : guards) {
            int i = guard[0], j = guard[1];
            grid[i][j] = -1;
            see(grid, dir[0], i + 1, j);
            see(grid, dir[1], i - 1, j);
            see(grid, dir[2], i, j + 1);
            see(grid, dir[3], i, j - 1);
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // cout << grid[i][j] << " ";
                cnt += !grid[i][j];
            }
            // cout << endl;
        }
        return cnt;
    }
}; */

class Solution {
    public: 
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0: unguarded, 1: guarded, -1: wall or guard
        vector<vector<int>> grid(m, vector<int>(n)); 

        for (auto& wall : walls)
            grid[wall[0]][wall[1]] = -1;

        for (auto& guard : guards)
            grid[guard[0]][guard[1]] = -1;

        auto mark_guarded = [&](int x, int y, int dx, int dy) {
            while (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] != -1) {
                if (!grid[x][y]) grid[x][y] = 1;
                x += dx;
                y += dy;
            }
        };

        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            mark_guarded(x + 1, y, 1, 0);  // Down
            mark_guarded(x - 1, y, -1, 0); // Up
            mark_guarded(x, y + 1, 0, 1);  // Right
            mark_guarded(x, y - 1, 0, -1); // Left
        }

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt += !grid[i][j];
            }
        }
        return cnt;
    }
};