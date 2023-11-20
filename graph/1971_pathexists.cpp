class Solution {
private: 
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int destination) {
        if (visited[curr]) return false;
        if (curr == destination) return true;
        visited[curr] = true;
        for (int i = 0; i < graph[curr].size(); ++i) {
            if (dfs(graph, visited, graph[curr][i], destination)) return true;
        }
        return false;
    } 
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        return dfs(graph, visited, source, destination);
    }
};