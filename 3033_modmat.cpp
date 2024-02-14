class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> cols;

        for (int col = 0; col < n; ++col) {
            int mx = 0;
            for (int row = 0; row < m; ++row) {
                mx = max(mx, matrix[row][col]);
            }
            cols.push_back(mx);
        }

        vector<vector<int>> res(m, vector<int>(n));
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (matrix[row][col] == -1) {
                    res[row][col] = cols[col];
                }
                else res[row][col] = matrix[row][col];
            }
        }
        return res;
    }
};