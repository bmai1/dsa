class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] >= 2 && grid[1][0] >= 2) return -1;

        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int time = curr[0], x1 = curr[1], y1 = curr[2];
            
            if (x1 == m - 1 && y1 == n - 1) return time;

            if (visited[x1][y1]) continue;
            visited[x1][y1] = true;

            for (auto [dx, dy] : dirs) {
                int x2 = x1 + dx;
                int y2 = y1 + dy;
                if (x2 >= 0 && y2 >= 0 && x2 < m && y2 < n && !visited[x2][y2]) {
                    // if next time is greater, move back and forth until can go to next
                    int next = (grid[x2][y2] - time) % 2 == 0;
                    // else take next + 1
                    pq.push({max(grid[x2][y2] + next, time + 1), x2, y2});
                }
            }
        }
        return -1;
    }
};