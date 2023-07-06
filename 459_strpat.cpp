class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // test cases: a, aaaa, aba, abab, aabb, abcba
        for (int i = 1; i < s.size(); ++i) {
            if (s.size() % i != 0) { continue; }
            string ss, tmp;
            for (int j = 0; j < i; ++j) {
                ss += s[j];
            }
            for (int k = 0; k < s.size() / i; ++k) {
                tmp += ss;
            }
            if (tmp == s) { return true; }
        }
        return false;
    }
};
