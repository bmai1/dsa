class Solution {
public:
    string reverseStr(string s, int k) {
        string ans = "";
        int n = s.size();
        int start = 0, i;
        while (n) {
            // move k characters forward
            for (i = start; i < start + k - 1; ++i) {
                if (i >= s.size() - 1) break; // < k characters remain
            }
            // append s[start] to s[k] reversed characters to answer
            for (int j = i; j >= start; --j) {
                ans += s[j];
                --n;
            }
            // append s[start + k] to s[start + 2 * k] characters to answer
            for (int l = start + k; l < start + (2 * k); ++l) {
                if (l > s.size() - 1) break; // >= k && < 2k characters remain
                ans += s[l];
                --n;
            }
            start += 2 * k;
        }
        return ans;  
    }
};