class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int i, int color) {
        visited[i] = color;
        for (int j = 0; j < graph[i].size(); ++j) {
            int k = graph[i][j]; // adjacent node
            if (visited[k] == -color) continue;
            if (visited[k] == color || !dfs(graph, visited, k, -color)) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // graph[i] = neighbors of node i 
        int m = graph.size();
        vector<int> visited(m);
        for (int i = 0; i < m; ++i) {
            if (!visited[i] && !dfs(graph, visited, i, 1)) {
                return false;
            }
        }
        return true;
    }
};