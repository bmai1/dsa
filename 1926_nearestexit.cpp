class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& st) {
        int m = maze.size(), n = maze[0].size();
        vector<int> dir = { -1, 0, 1, 0, -1 };
        queue<pair<int, int>> q;
        q.push({st[0], st[1]});
        maze[st[0]][st[1]] = '+';

        int d = 1; 
        while (!q.empty()) {
            int s = q.size(); // what's the point of this?
            while (s--) {
                auto p = q.front(); q.pop();
                // check four directions
                for (int i = 0; i < 4; ++i) {
                    int row = p.first + dir[i];
                    int col = p.second + dir[i + 1];
                    if (row >= 0 && col >= 0 && row < m && col < n && maze[row][col] == '.') {
                        if ((row != st[0] || col != st[1]) && (row == 0 || col == 0 || row == m - 1 || col == n - 1)) {
                            return d;
                        }
                        maze[row][col] = '+';
                        q.push({row, col});
                    }
                }
            }
            d++;
        }
        return -1;
    }
};
