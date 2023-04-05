class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; ++i) {
            ans[i].resize(i + 1);
            // front 
            ans[i][0] = 1;
            // middle
            for (int j = 1; j < i; ++j) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            // back
            ans[i][i] = 1;
        }
        return ans;
    }
};
