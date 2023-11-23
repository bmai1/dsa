class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int z, o, res = 0, n = s.size();
        for (int i = 0; i < n;) {
            if (s[i] == '0') {
                z = 0; o = 0;
                while (i < n && s[i] == '0') { ++z; ++i; }
                while (i < n && s[i] == '1') { ++o; ++i; }
                res = max(res, 2 * min(z, o));
            }
            else ++i;
        }
        return res;
    }
};