class Solution {
private:
    bool checkRow(vector<vector<int>>& mat, int i, int j) {
        for (int row = 0; row < mat.size(); ++row) {
            if (mat[row][j] && row != i) return false;
        }
        return true;
    }
    bool checkCol(vector<vector<int>>& mat, int i, int j) {
        for (int col = 0; col < mat[0].size(); ++col) {
            if (mat[i][col] && col != j) return false;
        }
        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0, m = mat.size(), n = mat[0].size();
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (mat[i][j]) {
        //             if (!checkRow(mat, i, j)) break; 
        //             else if (checkCol(mat, i, j)) ++ans;
        //         }
        //     }
        // }

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] && rows[i] == 1 && cols[j] == 1) ++ans;
            }
        }
        
        return ans;
    }
};