class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // int mx = 0, ans = 0;
        // vector<vector<int>> matrix(m, vector<int>(n, 0));
        // for (auto op : ops) {
        //     for (int x = 0; x < op[0]; ++x) {
        //         for (int y = 0; y < op[1]; ++y) {
        //             matrix[x][y]++;
        //             mx = max(mx, matrix[x][y]);
        //         }
        //     }
        // }
        // for (auto row : matrix) 
        //     for (auto col : row) 
        //         if (col == mx) ++ans;
        // return ans;

        int row = m, col = n;
        for (auto op : ops) {
            row = min(row, op[0]);
            col = min(col, op[1]);
        }
        return row * col;
    }
};