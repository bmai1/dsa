class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> sm(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0, cnt = 0;
                for (int v = i - 1; v < i + 2; ++v) {
                    for (int h = j - 1; h < j + 2; ++h) {
                        if (v >= 0 && v < m && h >= 0 && h < n) {
                            ++cnt;
                            sum += img[v][h];
                        }
                    }
                }
                sm[i][j] = floor(sum / cnt);
            }
        }
        return sm;
    }
};