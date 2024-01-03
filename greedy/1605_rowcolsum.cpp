class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(n, vector<int>(m));
        int mn;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mn = min(rowSum[i], colSum[j]);
                res[i][j] = mn;
                rowSum[i] -= mn;
                colSum[j] -= mn;
            }
        }
        return res;
    }
};