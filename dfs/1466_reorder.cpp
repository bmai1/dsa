class Solution {
private:
    int cnt = 0;
    unordered_map<int, vector<int>> adj, back;
    void dfs(int root, vector<bool>& visited) {
        visited[root] = true;
        for (int i : adj[root]) {
            if (!visited[i]) {
                ++cnt;
                dfs(i, visited);
            }    
        }
        for (int i : back[root]) 
            if (!visited[i]) dfs(i, visited);
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        // construct graphs
        for (auto edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            back[edge[1]].push_back(edge[0]);
        }
        dfs(0, visited);
        return cnt;
    }
};