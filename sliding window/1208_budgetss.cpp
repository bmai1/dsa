class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), i = 0, j;
        for (j = 0; j < n; ++j) {
            maxCost -= abs(s[j] - t[j]);
            if (maxCost < 0) {
                maxCost += abs(s[i] - t[i]);
                ++i;
            }
        }
        return j - i;
    }
};