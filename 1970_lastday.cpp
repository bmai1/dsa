class Solution {

private: 
    // int lastDay = 0;
    // void dfs(int row, int col, vector<vector<int>>& cells, vector<vector<int>>& grid, vector<vector<bool>>& visited, int day) {
    //     if (row < 0 || col < 0 || row > grid.size() - 1 || col > grid[0].size() - 1) { return; }
    //     if (grid[row][col] == 1 || visited[row][col] == true) { return; }
    //     visited[row][col] = true; 
    //     if (row == grid.size() - 1) { 
    //         lastDay = max(lastDay, day); 
    //         return;
    //     }
    //     dfs(row + 1, col, cells, grid, visited, day);
    //     dfs(row - 1, col, cells, grid, visited, day);
    //     dfs(row, col + 1, cells, grid, visited, day);
    //     dfs(row, col - 1, cells, grid, visited, day);
    // }
    
    // vector<int> parent;
    // int find(int x) {
    //     return parent[x] = x ? x : find(parent[x]);
    // }

    int dir[5] = {0, 1, 0, -1, 0};
    bool canWalk (int row, int col, int day, vector<vector<int>>& cells) {
        vector<vector<bool>> grid(row, vector<bool>(col, false));
        for (int i = 0; i < day; ++i) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = true; 
        }
        // bfs using queue (FIFO)
        queue<pair<int, int>> bfs;
        for (int i = 0; i < col; ++i) {
            // start row cells
            if (grid[0][i] == 0) {
                bfs.push({0, i});
                grid[0][i] = 1;
            }
        }
        while (!bfs.empty()) {
            auto [r, c] = bfs.front(); bfs.pop();
            if (r == row - 1) { return true; }
            for (int i = 0; i < 4; ++i) {
                int nextRow = r + dir[i], nextCol = c + dir[i + 1];
                if (nextRow < 0 || nextCol < 0 || nextRow > row - 1 || nextCol > col - 1) { continue; }
                // flooded/visited cell
                if (grid[nextRow][nextCol]) { continue; }
                grid[nextRow][nextCol] = true; 
                bfs.push({nextRow, nextCol});
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(); 
        int ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canWalk(row, col, mid, cells)) {
                // mid is the ith last day the graph is connected
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;

        // vector<vector<int>> grid(row, vector<int>(col, 1));
        // int n = cells.size();
        // int lastDay = 0; 
        // parent.resize(n, 0);
        // for (int i = 0; i < n; ++i) { parent[i] = i; } 

        // vector<int> rank;
        // for (int i = 0; i < n; ++i) {
            
        //     for (int j = i + 1; j < n; ++j) {
        //         if ([i][j])
        //     }
        // }

        // return lastDay;

        // vector<vector<int>> grid(rows, vector<int>(cols, 0));
        // vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        // for (int day = 0; day < rows; ++day) {
        //     grid[cells[day][0] - 1][cells[day][1] - 1] = 1;
        //     for (int col = 0; col < cols; ++col) {
        //         vector<vector<bool>> tmp = visited;
        //         // start from top row, loop through columns
        //         dfs(0, col, cells, grid, tmp, day);
        //     }
        // } 
        // return lastDay + 1;
    }
};
