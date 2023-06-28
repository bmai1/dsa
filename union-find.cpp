// identify if problem talks about finding groups or components
class Solution {
    vector<int> parent; 
    // keeps going until index of x value is found in parent
    // assumed that indexes will connect in graph
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        parent.resize(n + 1, 0); // fills with zeroes
        for (int i = 0; i < n + 1; ++i) {
            parent[i] = i;
        }

        vector<int> ans(2, 0);
        for (int i = 0; i < n; ++i) {
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
            // merge
            if (x != y) {
                parent[y] = x;
            }
            else {
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
            }
        }
        // what is the "redundant connection"?
        return ans; 
    }
};
