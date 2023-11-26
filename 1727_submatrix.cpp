class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> height(n, 0);
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                matrix[row][col] ? ++height[col] : height[col] = 0;
            }
            vector<int> tmp = height;
            sort(tmp.begin(), tmp.end());
            for (int col = 0; col < n; ++col) {
                res = max(res, tmp[col] * (n - col));
            }
        }
        return res;
    }
};