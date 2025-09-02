class Solution {
public:
    int maxDifference(string s) {
        int cnt[26] = {};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int res = INT_MIN;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i != j && cnt[i] && cnt[j] && cnt[i] % 2 != 0 && cnt[j] % 2 == 0) {
                    res = max(res, cnt[i] - cnt[j]);
                }
            }
        }
        return res;
    }
};
