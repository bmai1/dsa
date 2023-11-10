class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjPairs) {
        unordered_map<int, vector<int>> pairs;
        for (auto &pair : adjPairs) {
            pairs[pair[0]].push_back(pair[1]);
            pairs[pair[1]].push_back(pair[0]);
        }
        vector<int> ori;
        // all elements appear twice except front and end
        for (auto &pair : pairs) {
            // found root (start or end)
            if (pair.second.size() == 1) {
                ori.push_back(pair.first);
                ori.push_back(pair.second[0]);
                break;
            }
        }
        while (ori.size() < adjPairs.size() + 1) {
            auto tail = ori.back(), prev = ori[ori.size() - 2];
            auto &next = pairs[tail];
            if (next[0] != prev) ori.push_back(next[0]);
            else ori.push_back(next[1]);
        }
        return ori;
    }
};