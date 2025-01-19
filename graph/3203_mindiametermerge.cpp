class Solution {
private:
    pair<int, int> dfs(int start, vector<vector<int>>& adj) {
        vector<bool> visited(adj.size());
        stack<pair<int, int>> stk;
        stk.push({start, 0});
        int farthest_node = start, max_dist = 0;

        while (!stk.empty()) {
            auto [node, dist] = stk.top(); stk.pop();
            if (dist > max_dist) {
                farthest_node = node;
                max_dist = dist;
            }
            visited[node] = true;
            for (int next : adj[node]) {
                if (!visited[next]) {
                    stk.push({next, dist + 1});
                }
            }
        }
        
        return {farthest_node, max_dist};
    }

    int diameter(vector<vector<int>>& adj) {
    auto [a, _]        = dfs(0, adj); // Find node A
    auto [b, diameter] = dfs(a, adj); // Find node B and the diameter
    return diameter;
}
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // find diameter of both trees
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for (auto edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for (auto edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int dia1 = diameter(adj1), dia2 = diameter(adj2);
        // cout << dia1 << " " << dia2 << endl;
        return max((dia1 + 1) / 2 + (dia2 + 1) / 2 + 1, max(dia1, dia2));
    }
};
