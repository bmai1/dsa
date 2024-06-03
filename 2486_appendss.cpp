class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0, cnt = 0;
        while (j < t.size()) {
            if (s[i] == t[j]) {
                ++i, ++j;
            }
            else while (i < s.size() && s[i] != t[j]) ++i;
            if (i == s.size() && j != t.size()) return t.size() - j;
        }
        return cnt;
    }
};