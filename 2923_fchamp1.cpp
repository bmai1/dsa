class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> w(n, true);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (grid[i][j]) {
                        // not j
                        w[j] = false;
                    }
                    else {
                        // not i
                        w[i] = false;
                    }
                }
            }
        }
        for (int i = 0; i < w.size(); ++i) if (w[i]) return i;
        return -1;
    }
};