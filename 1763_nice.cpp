class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string res = "";
        int sz = INT_MIN;
        unordered_map<char, int> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n - i + 1; ++j) {
                string ss = s.substr(i, j);
                // cout << ss << endl;
                for (auto c : ss) m[c]++;
                bool nice = true;
                for (auto [k, v] : m) {
                    if (!m[tolower(k)] || !m[toupper(k)]) {
                        nice = false;
                        break;
                    }
                }
                if (nice && j > sz) {
                    sz = j;
                    res = ss;
                    // cout << "RES: " << res << endl;
                }
                else if (!nice) m.clear();
            }
        }
        return res;
    }
};