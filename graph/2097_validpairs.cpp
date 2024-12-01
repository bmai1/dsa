class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> outdegree, indegree;

        for (auto& pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            outdegree[pair[0]]++;
            indegree[pair[1]]++;
        }

        // start has no end match for pair[1]
        int start = pairs[0][0];
        for (auto& [node, degree] : outdegree) {
            if (outdegree[node] - indegree[node] == 1) {
                start = node;
                break;
            }
        }

        // Hierholzer's Algorithm
        vector<int> stack, path;
        stack.push_back(start);

        while (!stack.empty()) {
            int node = stack.back();
            if (!adj[node].empty()) {
                int next = adj[node].back();
                adj[node].pop_back();
                stack.push_back(next);
            } 
            else {
                path.push_back(node);
                stack.pop_back();
            }
        }

        reverse(path.begin(), path.end());

        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; ++i) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;

        // dfs TLE
        // unordered_map<int, vector<vector<int>>> start;
        // unordered_map<int, vector<vector<int>>> end;
        // for (auto pair : pairs) {
        //     start[pair[0]].push_back(pair);
        //     end[pair[1]].push_back(pair);
        // }

        // stack<vector<vector<int>>> stk;

        // for (auto pair : pairs) {
        //     // find head (no match for start)
        //     if (end[pair[0]].empty()) {
        //         stk.push({pair});
        //         break;
        //     }
        // }

        // // start from anywhere
        // if (stk.empty()) {
        //     stk.push({pairs[0]});
        // }
    
        // while (!stk.empty()) {
        //     auto curr = stk.top(); stk.pop();
        //     if (curr.size() == pairs.size()) return curr;

        //     set<vector<int>> visited(curr.begin(), curr.end());

        //     for (auto& next : start[curr.back()[1]]) {
        //         if (!visited.contains(next)) {
        //             visited.insert(next);
        //             curr.push_back(next);
        //             stk.push(curr);
        //             curr.pop_back();
        //         }
        //     }
        // }

        // return pairs;

        // gigachad brute force
        // while (next_permutation(pairs.begin(), pairs.end())) {
        //     bool flag = true;
        //     for (int i = 0; i < pairs.size() - 1; ++i) {
        //         if (pairs[i][1] != pairs[i + 1][0]) {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if (flag) return pairs;
        // }
        // return pairs;
    }
};