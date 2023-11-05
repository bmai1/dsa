class Solution {
private: 
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> w(n, true);
        for (int edge = 0; edge < edges.size(); ++edge) {
            w[edges[edge][1]] = false;
        }
        int res = -1;
        for (int i = 0; i < w.size(); ++i) {
            if (w[i]) {
                if (res == -1) res = i;
                else return -1;
            }
        }
        return res;
    }
};