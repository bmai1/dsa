class Solution {
private:
    vector<int> parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
        // while (x != parent[x]) {
        //     parent[x] = parent[parent[x]];
        //     x = parent[x];
        // }
        // return x;
    }
public:
    int findCircleNum(vector<vector<int>>& c) {
        int n = c.size();
        int count = n; 
        parent.resize(n, 0);
        for (int i = 0; i < n; ++i) { parent[i] = i; }
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (c[i][j]) {
                    int x = find(i);
                    int y = find(j);
                    if (x != y) {
                        parent[x] = y;
                        --count;
                    }
                }
            }
        }
        return count;

        // vector<int> rank(n, 0); 
        // parent.resize(n, 0);
        // for (int i = 0; i < n; ++i) {
        //     parent[i] = i;
        // }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         if (c[i][j] == 1) {
        //             // union
        //             int x = find(i);
        //             int y = find(j);
        //             if (x == y) { continue; }
        //             if (rank[y] > rank[x]) {
        //                 parent[x] = y;
        //             }
        //             else {
        //                 parent[y] = x;
        //                 if (rank[x] == rank[y]) { ++rank[x]; }
        //             }
        //             --count;
        //         }
        //     }
        // }
    }
};
