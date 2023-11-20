class Solution {
private: 
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int destination) {
        if (visited[curr]) return false;
        if (curr == destination) return true;
        visited[curr] = true;
        for (auto node : graph[curr]) {
            if (dfs(graph, visited, node, destination)) return true;
        }
        return false;
    } 
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(graph, visited, source, destination);
    }
};