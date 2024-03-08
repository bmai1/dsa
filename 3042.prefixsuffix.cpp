class Solution {
private:
    bool isPrefixAndSuffix(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        for (int i = 0; i < m; ++i) {
            if (s1[i] != s2[i] || s1[i] != s2[n - m + i]) return false;
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cnt += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return cnt;
    }
};