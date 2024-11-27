class Solution {
private:
    int shortest_path(int n, vector<vector<int>>& adj) {
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;

        // start from 0, find n - 1
        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [city, len] = q.front(); q.pop();
            if (city == n - 1) return len;
            for (int next : adj[city]) {
                if (!visited[next]) {
                    q.push({next, len + 1});
                    visited[next] = true;
                }
            }
        }
        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            adj[i].push_back(i + 1);
            // can't go backwards (unidirectional)
            // adj[i + 1].push_back(i);
        }
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            adj[u].push_back(v);
            // adj[v].push_back(u);
            res.push_back(shortest_path(n, adj));
        }
        return res;
    }
};