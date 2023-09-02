class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = 0, max_ones = 0;
        for (int i = 0; i < mat.size(); ++i) {
            int ones = 0;
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j]) ++ones;
            }
            if (ones > max_ones) {
                max_ones = ones;
                row = i;
            }
        }
        return {row, max_ones}; 
    }
};
