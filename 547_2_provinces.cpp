class Solution {
private:
    void dfs(vector<vector<int>> &c, vector<bool> &visited, int i) {
        visited[i] = true;
        for (int j = 0; j < visited.size(); ++j) {
            if (i != j && c[i][j] && !visited[j]) {
                dfs(c, visited, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& c) {
        if (c.empty()) { return 0; }
        int n = c.size();
        int provinces = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < visited.size(); ++i) {
            if (visited[i] == false) {
                ++provinces;
                dfs(c, visited, i);
            }
        }
        return provinces;
    }
};
