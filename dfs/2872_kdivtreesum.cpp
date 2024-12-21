class Solution {
private:
    int cnt = 0;
    int dfs(vector<vector<int>>& adj, vector<int>& values, vector<bool>& visited, int k, int node) {
        visited[node] = true;
        int sum = values[node];
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                sum += dfs(adj, values, visited, k, neighbor);
            }
        }
        cnt += sum % k == 0;
        return sum % k;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // create adj list
        // from 0, dfs and track value sum
        // when sum % k == 0 split tree
        
        vector<vector<int>> adj(n);
        for (const auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n);
        dfs(adj, values, visited, k, 0);

        return cnt;
    }
};
