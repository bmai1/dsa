class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0, n = s.size();
        if (n < 3) return 0;
        for (int i = 2; i < n; ++i) 
            if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) ++ans;
        return ans;
    }
};