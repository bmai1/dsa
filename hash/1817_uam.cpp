class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        unordered_map<int, unordered_set<int>> UAM;
        for (auto &log : logs) {
            UAM[log[0]].insert(log[1]);
        }
        for (auto &it : UAM) {
            ++ans[it.second.size() - 1];
        }
        return ans;
    }
};