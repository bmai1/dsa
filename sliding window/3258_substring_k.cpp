class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        unordered_map<char, int> m;
        int n = s.size(), res = 0, i = 0, j;

        for (j = 0; j < n; ++j) {
            ++m[s[j]];
            while (m['0'] > k && m['1'] > k) {
                --m[s[i++]];
            }
            res += j - i + 1;
        }

        return res;
    }
};
