class Solution {
private:
    vector<int> safe_cache; // 0 - not visited, 1 - visiting, 2 - safe
    bool dfs(vector<vector<int>>& graph, int node) {
        if (safe_cache[node] > 0) return safe_cache[node] == 2; 

        safe_cache[node] = 1; 
        for (int next : graph[node]) {
            if (safe_cache[next] == 1 || !dfs(graph, next)) {
                return false;
            }
        }

        safe_cache[node] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        safe_cache.resize(n, false);

        for (int i = 0; i < n; ++i) {
            if (dfs(graph, i)) res.push_back(i);
        }

        return res;
    }
};
