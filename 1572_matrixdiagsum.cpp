class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // side length of square
        int l = mat.size();
        int sum = 0, row = 0, col = 0;
        // first diagonal
        for (int i = 0; i < l; ++i) {
            sum += mat[row++][col++];
        }
        row = 0, col = l - 1;
        // second diagonal
        for (int j = 0; j < l; ++j) {
            sum += mat[row++][col--];
        }
        // if odd side length then subtract middle overlapping element
        return l % 2 == 0 ? sum : sum - mat[l - (l + 1) / 2][l - (l + 1) / 2];
    }
};
