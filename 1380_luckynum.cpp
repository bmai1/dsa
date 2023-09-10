class Solution {
    bool minInRow(vector<int>& a, int& n) {
        for (int num : a) if (num < n) return false;
        return true;
    }
    bool maxInCol(vector<vector<int>>& matrix, int& col, int& n) {
        for (auto r : matrix) if (r[col] > n) return false;
        return true;
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (minInRow(matrix[i], matrix[i][j]) && maxInCol(matrix, j, matrix[i][j])) {
                    ans.push_back(matrix[i][j]);
                }
            }
        } 
        return ans;
    }
};