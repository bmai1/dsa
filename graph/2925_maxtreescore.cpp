class Solution {
private:
    typedef long long ll;
    pair<ll, ll> dfs(vector<vector<int>>& tree, vector<int>& values, int node, int parent) {
        ll take = 0, pass = 0;

        // scan graph and dfs
        for (auto child : tree[node]) {
            if (child == parent) continue;
            auto [t, p] = dfs(tree, values, child, node);
            take += t;
            pass += p;
        }

        // take curr node or children, main dfs logic
        take += pass != 0 ? max(pass, (ll) values[node]) : 0;
        pass  = pass != 0 ? min(pass, (ll) values[node]) : values[node];

        return { take, pass };
    }
        
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> tree(values.size());
        // construct graph from edges
        for (auto e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        return dfs(tree, values, 0, -1).first;
    }
};