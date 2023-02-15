class Solution {
public:
    void dfs(vector<vector<int>>& img, int sr, int sc, int start, int color) {
        // dfs layout
        // base condition of return: can't exit boundaries (0 <= sr, 0 <= sc)
        // can't be visited node
        if (sr < 0 || sr >= img.size() || sc < 0 || sc >= img[0].size() || img[sr][sc] == color || img[sr][sc] != start) {
            return;
        }
        img[sr][sc] = color;
        // recursion on surrounding nodes
        dfs(img, sr + 1, sc, start, color);
        dfs(img, sr - 1, sc, start, color);
        dfs(img, sr, sc + 1, start, color);
        dfs(img, sr, sc - 1, start, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int start = img[sr][sc];
        dfs(img, sr, sc, start, color);
        return img;
    }
};
