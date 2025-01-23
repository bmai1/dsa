class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();

        // {height, i, j}

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        // push first/last row/col heights
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int i = 0; i < n; ++i) {
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[m - 1][i], m - 1, i});
            visited[0][i] = visited[m - 1][i] = true;
        }

        int volume = 0;

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int min_height = top[0], row = top[1], col = top[2];
            
            for (auto dir : dirs) {
                int next_row = row + dir.first;
                int next_col = col + dir.second;

                if (next_row >= 0 && next_col >= 0 && next_row < m && next_col < n && !visited[next_row][next_col]) {
                    int next_height = heightMap[next_row][next_col];
                    if (next_height < min_height) {
                        volume += min_height - next_height;
                    }
                    pq.push({max(next_height, min_height), next_row, next_col});
                    visited[next_row][next_col] = true;
                }
            }

        }

        return volume;
    }
};
