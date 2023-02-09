class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        vector<vector<int>> ans; 
        int n = groupSizes.size();
        for (int i = 0; i < n; ++i) {
            // single group (loner irl)
            if (groupSizes[i] == 1) { ans.push_back({i}); }
            else {
                m[groupSizes[i]].push_back(i);
                // check if group is full
                if (m[groupSizes[i]].size() == groupSizes[i]) {
                    ans.push_back(m[groupSizes[i]]);
                    m[groupSizes[i]].clear(); 
                }
            }
        }
        return ans; 
    }
};
