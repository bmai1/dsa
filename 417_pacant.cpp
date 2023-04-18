class Solution {
private:
    void s(vector<vector<int>>& h, vector<vector<bool>>& ocean, int i, int j) {
        if (ocean[i][j] == true) { return; }
        int m = h.size(), n = h[0].size();
        ocean[i][j] = true;
        if (i - 1 >= 0 && ocean[i - 1][j] != true && h[i - 1][j] >= h[i][j]) s(h, ocean, i - 1, j);
        if (i + 1 < m && ocean[i + 1][j] != true && h[i + 1][j] >= h[i][j]) s(h, ocean, i + 1, j);
        if (j - 1 >= 0 && ocean[i][j - 1] != true && h[i][j - 1] >= h[i][j]) s(h, ocean, i, j - 1);
        if (j + 1 < n && ocean[i][j + 1] != true && h[i][j + 1] >= h[i][j]) s(h, ocean, i, j + 1);
    }
public:  
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            s(heights, p, i, 0);
            s(heights, a, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            s(heights, p, 0, j);
            s(heights, a, m - 1, j);
        }
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[0].size(); ++j) {
                if (p[i][j] && a[i][j]) { res.push_back({i, j}); }
            }
        } 
        return res;
    }
};
