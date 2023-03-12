class Solution {
private:
    // offset to neighbors
    static constexpr int y[] = { -1, -1, -1,  1, 1, 1,  0, 0 };
    static constexpr int x[] = { -1,  0,  1, -1, 0, 1, -1, 1 };
    bool boundary(int i, int j, int m, int n) {
        if (i < 0 || i >= m) { return false; }
        if (j < 0 || j >= n) { return false; }
        return true;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> tmp = board;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                for (int k = 0; k < 8; ++k) {
                    if (boundary(i + y[k], j + x[k], m, n)) {
                        if (tmp[i + y[k]][j + x[k]] == 1) { ++live; }
                    }
                }
                if (live == 3) { board[i][j] = 1; }
                else if (live < 2 || live > 3) { board[i][j] = 0; }
            }
        }
    }
};
