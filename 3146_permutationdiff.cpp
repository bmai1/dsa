class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int diff[26] = {};
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            diff[s[i] - 'a'] = i;
        }
        for (int i = 0; i < t.size(); ++i) {
            res += abs(diff[t[i] - 'a'] - i);
        }
        return res;
    }
};