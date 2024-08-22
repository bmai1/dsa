class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int b[11][11];
        int seen[11];
        int res = 0;
        for (auto p : pick) {
            if (!seen[p[0]] && ++b[p[0]][p[1]] > p[0]) {
                ++res;
                ++seen[p[0]];
            }
        }
        return res;
    }
};