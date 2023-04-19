class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir = {-1, 0, 1, 0, -1}; // 4 adj coords
        int m = grid.size();
        int n = grid[0].size();
        
        // mental map for intuition --> using queues for BFS
        // to remember to get the next vertex to start a search when a dead end occurs in any iteration.
        queue<pair<int, int>> q;
        int fresh = 0; // fresh orag left
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // adding rows and column pairs of rotten orag
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } 
                else if (grid[i][j] == 1) { ++fresh; }
            }
        }
        int mins = -1; // start at -1 
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                // can also do auto[r, c] which is less readable
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    // adj coords
                    int row = p.first + dir[i];
                    // col + 1 
                    int col = p.second + dir[i + 1];
                    // base case to change fresh orag
                    // positive row number, row less than grid size (# rows)
                    // col less than grid row length (# cols)
                    // fresh orag to change
                    if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        // queue push row and col of rotten again 
                        q.push({row, col});
                        --fresh;
                    }
                }
            }
            ++mins;
        }
        if (fresh > 0) { return -1; } // still fresh orag
        if (mins == -1) { return 0; } // no orag = 0 mins
        return mins;
    }
};
