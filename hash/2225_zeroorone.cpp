class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> l0, l1;
        map<int, int> l;
        for (auto m : matches) {
            if (!l[m[0]]) l[m[0]] = 0;
            l[m[1]]++;
        }
        for (auto it : l) {
            if (!it.second) l0.push_back(it.first);
            if (it.second == 1) l1.push_back(it.first);
        }
        return {l0, l1};
    }
};