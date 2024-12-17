
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        deque<pair<int, int>> dq;

        dp[0][0] = 0;
        dq.push_front({0, 0});
        visited[0][0] = true;

        while (!dq.empty()) {
            auto [x, y] = dq.front(); 
            dq.pop_front();
            for (int i = 0; i < 4; ++i) {
                int _x = x + dirs[i].first;
                int _y = y + dirs[i].second;
                if (_x >= 0 && _y >= 0 && _x < m && _y < n && !visited[_x][_y]) {
                    dp[_x][_y] = dp[x][y] + (grid[_x][_y] == 1);
                    // 0-1 BFS, push to back if removed obstacle, instead of using priority queue to sort by cost
                    if (grid[_x][_y]) dq.push_back({_x, _y});
                    else dq.push_front({_x, _y});
                    visited[_x][_y] = true;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};