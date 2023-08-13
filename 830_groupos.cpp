class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        vector<int> group = {0,0};
        int cnt = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                if (cnt >= 3) {
                    group[1] = group[0] + cnt - 1;
                    ans.push_back(group);
                }
                group[0] = i;
                cnt = 1;
            }
            else ++cnt;
        }
        // handle end group
        if (cnt >= 3) {
            group[1] = group[0] + cnt - 1;
            ans.push_back(group);
        }
        return ans;
    }
};