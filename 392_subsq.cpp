class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int j = 0;
        for (int i = 0; i < m && j < n; ++i) {
            if (s[j] == t[i]) {
                j++;
            }
        }
        // number of char matches
        return (j == n);
    }
};
