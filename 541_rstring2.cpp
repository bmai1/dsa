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

        string ans = "";
        int n = s.size() - 1; // last index before overflow
        int i = 0; 
        for (;;) {
            // move j forward k characters (go to end if <k remain)
            int j = min(n, i + k - 1);
            // append s[j..i] to answer (reversed s[i..j])
            for (j; j >= i; --j) ans += s[j];
            // append s[i+k..i+(2*k)] to answer
            for (int l = i + k; l < i + 2 * k; ++l) {
                if (l > n) return ans; // finished reversal
                ans += s[l];
            }
            i += 2 * k; // new start index
        }
        return "cum";  
    }
};