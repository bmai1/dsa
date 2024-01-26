class Solution {
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int move(int m, int n, int row, int col, int moves) {
        if (moves == -1) return 0;
        if (row < 0 || row >= m || col < 0 || col >= n) return 1;
        if (dp[row][col][moves] != -1) return dp[row][col][moves];
        
        int up = move(m, n, row - 1, col, moves - 1);
        int down = move(m, n, row + 1, col, moves - 1);
        int left = move(m, n, row, col - 1, moves - 1);
        int right = move(m, n, row, col + 1, moves - 1);

        return dp[row][col][moves] = ((long long) up + down + left + right) % mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return move(m, n, startRow, startColumn, maxMove);
    }
};