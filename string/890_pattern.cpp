class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;

        for (string s : words) {
            if (s.size() != pattern.size()) continue;
            unordered_map<int, int> m;
            unordered_set<int> st;
            bool match = true;
            for (int i = 0; i < s.size(); ++i) {
                if (!m[s[i]]) {
                    // maps to more than one
                    if (st.count(pattern[i]) == 1) {
                        match = false;
                        break;
                    }
                    m[s[i]] = pattern[i];
                    st.insert(pattern[i]);
                }
                // maps to wrong letter
                if (m[s[i]] != pattern[i]) {
                    match = false;
                    break;
                }
            }
            // int c[123] = {};
            // for (auto it : m) c[it.second]++;
            // for (int i = 61; i < 123; ++i) {
            //     if (c[i] > 1) {
            //         match = false;
            //         break;
            //     }
            // }
            if (match) res.push_back(s);
        }

        return res;
    }
};