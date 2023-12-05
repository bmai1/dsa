class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, vector<int> path, int curr, int target) {
        path.push_back(curr);
        if (curr == target) {
            res.push_back(path);
            return;
        }
        for (auto node : graph[curr]) {
            dfs(graph, path, node, target);
        }
    } 
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        for (auto node : graph[0]) {
            vector<int> path = {0};
            dfs(graph, path, node, graph.size() - 1);
        }
        return res;
    }
};