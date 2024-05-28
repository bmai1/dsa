class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> m;
        int n = s.size(), res = 0;
        for (int u = 1; u <= 26; ++u) {
            m.clear();
            int start = 0, end = 0, unique = 0, valid = 0;
            while (end < n) {
                if (unique <= u) {
                    if (!m[s[end]]) ++unique;
                    if (++m[s[end++]] == k) ++valid;
                }
                // shrink window
                while (unique > u) {
                    if (m[s[start]] == k) --valid;
                    if (!--m[s[start++]]) --unique;
                }
                if (unique == u && unique == valid) {
                    res = max(res, end - start);
                }
            }
        }
        return res;
    }
};