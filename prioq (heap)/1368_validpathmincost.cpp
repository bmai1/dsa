class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        vector<int> dirs = {1, 2, 3, 4};
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int cost = top[0], i = top[1], j = top[2];

            if (i == m - 1 && j == n - 1) {
                return cost; // found min path since heap sorts by distance
            }

            if (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j]) {
                visited[i][j] = true;
                for (int dir : dirs) {
                    int new_i = i + (dir == 3) - (dir == 4);
                    int new_j = j + (dir == 1) - (dir == 2);
                    if (dir != grid[i][j]) {
                        pq.push({cost + 1, new_i, new_j});
                    }
                    else {
                        pq.push({cost, new_i, new_j});
                    }
                }
            }
        }

        return -1;
    }
};
