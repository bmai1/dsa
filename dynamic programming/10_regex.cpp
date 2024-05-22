class Solution {
private:
    bool re(int i, int j, string& s, string& p) {
        if (j == p.size()) return i == s.size();
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // zero occurence or keep matching p
            return re(i, j + 2, s, p) || (match && re(i + 1, j, s, p));
        }
        return match && re(i + 1, j + 1, s, p);
    }

public:
    bool isMatch(string s, string p) {
        return re(0, 0, s, p);
    }
};