class Solution {
private:
    vector<vector<string>> ans;
    vector<string> state;

    bool valid(int row, int col, int n) {
        for (int i = 0; i < row; ++i) {
            if (state[i][col] == 'Q') return false;
        }
        // left diag
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (state[i][j] == 'Q') return false;
        }
        // right diag
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (state[i][j] == 'Q') return false;
        }
        return true;
    }

    void bt(int row, int n) {
        if (row == n) {
            ans.push_back(state);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (valid(row, col, n)) {
                state[row][col] = 'Q';
                bt(row + 1, n);
                state[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        state = vector<string> (n, string(n, '.'));
        bt(0, n);
        return ans;
    }
};