class Solution {
public:
    string findValidPair(string s) {
        int d[10] = {};
        for (char c : s) d[c - '0']++;
        for (int i = 0; i < s.size() - 1; ++i) {
            int d1 = s[i] - '0';
            int d2 = s[i + 1] - '0';
            if (d1 != d2 && d1 == d[d1] && d2 == d[d2]) {
                return string(s, i, 2);
            }
        }
        return "";
    }
};
