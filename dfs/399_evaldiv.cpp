class Solution {
private:
    // weight of edges (equation value) represented by pair.second
    unordered_map<string, vector<pair<string, double>>> graph; 
    double dfs(string curr, string target, unordered_set<string>& visited) {
        if (curr == target) return 1.0;
        visited.insert(curr);
        for (const auto& neighbor : graph[curr]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double tmp = dfs(neighbor.first, target, visited);
                if (tmp != -1.0) {
                    return tmp * neighbor.second;
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // construct graph 
        for (int i = 0; i < equations.size(); ++i) {
            // add edges and weight
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double weight = values[i];
            graph[a].push_back({b, weight});
            graph[b].push_back({a, 1.0 / weight});
        }

        vector<double> ans;
        for (const auto& q : queries) {
            unordered_set<string> visited;
            if (graph.find(q[0]) != graph.end() && graph.find(q[1]) != graph.end()) {
                ans.push_back(dfs(q[0], q[1], visited));
            }
            else ans.push_back(-1.0);
        }
        return ans;
    }
};