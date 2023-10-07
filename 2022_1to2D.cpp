class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};
        vector<vector<int>> ans(m, vector<int>(n));
        int i = 0, row = 0;
        while (i < original.size(); ) {
            for (int col = 0; col < n; ++col) {
                ans[row][col] = original[i++];
            }
            ++row;
        }
        return ans;
    }
};