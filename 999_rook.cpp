class Solution {
    bool c(int row, int col, int dir, vector<vector<char>>& board) {
        if (row < 0 || col < 0 || row > board.size() - 1 || col > board[0].size() - 1) return false;
        if (board[row][col] == 'B') return false;
        else if (board[row][col] == 'p') return true;
        else {
            if (dir == 1) return c(row - 1, col, 1, board);
            if (dir == 2) return c(row + 1, col, 2, board);
            if (dir == 3) return c(row, col - 1, 3, board);
            if (dir == 4) return c(row, col + 1, 4, board);
        }
        return false;
    }
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0, m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'R') {
                    // (up: 1, down: 2, left: 3, right: 4)
                    return c(i - 1, j, 1, board) + c(i + 1, j, 2, board) + c(i, j - 1, 3, board) + c(i, j + 1, 4, board);
                }
            }
        }
        return -1;
    }
};