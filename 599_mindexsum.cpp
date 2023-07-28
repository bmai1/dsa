class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int mn = INT_MAX;

        // for (int i = 0; i < list1.size(); ++i) {
        //     for (int j = 0; j < list2.size(); ++j) {
        //         if (list1[i] == list2[j]) m = min(m, i + j);
        //     }
        // }
        // for (int i = 0; i < list1.size(); ++i) {
        //     for (int j = 0; j < list2.size(); ++j) {
        //         if (list1[i] == list2[j] && i + j == m) ans.push_back(list1[i]);
        //     }
        // }

        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); ++i) m[list1[i]] = i;
        for (int i = 0; i < list2.size(); ++i) {
            if (m.count(list2[i]) != 0) {
                if (m[list2[i]] + i < mn) {
                    mn = min(mn, m[list2[i]] + i);
                    ans.clear(), ans.push_back(list2[i]);
                }
                else if (m[list2[i]] + i == mn) ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};