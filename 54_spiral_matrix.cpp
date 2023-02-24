class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; 
        int m = matrix.size(), n = matrix[0].size();
        if (m == 1) { return matrix[0]; }
        if (n == 1) {
            for (auto v: matrix) {
                ans.push_back(v[0]);
            }
            return ans;
        }
        int i = 0, j = 0, count = m * n + 1;
        while (--count) {
            // cout << i << ' ' << j << endl;
            // cout << matrix[i][j] << endl;
            ans.push_back(matrix[i][j]);
            // mark as seen
            matrix[i][j] = -999;
            // top boundary, move right
            if (j < n - 1 && (i == 0 || matrix[i - 1][j] == -999) && matrix[i][j + 1] != -999) { ++j; }
            // bottom boundary, move left
            else if (j - 1 >= 0 && (i + 1 > m - 1 || matrix[i + 1][j] == -999) && matrix[i][j - 1] != -999) { --j; }
            // right boundary, move down 
            else if (i <= m - 2 && (j == n - 1 || matrix[i][j + 1] == -999) && matrix[i + 1][j] != -999) { ++i; }
            // left boundary, move up
            else if (i - 1 >= 0 && (j - 1 < 0 || matrix[i][j - 1] == -999) && matrix[i - 1][j] != -999) { --i; } 
        }
        return ans;
    }
};
