class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i) {
            int max_row = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '#') {
                    res[max_row][m - i - 1] = '#';
                    --max_row;
                }
                if (box[i][j] == '*') {
                    res[j][m - i - 1] = '*';
                    max_row = j - 1;
                }
            }
        }

        return res;
    }
};