class Solution {
public: 
    string longestPalindrome(string s) {
        // two pointers approach
        if (s.length() == 1) return s; 
        int n = s.length();
        // indices of palindrome, end is also maxLength
        int start = 0, end = 0;

        int right, left;
        for (int i = 0; i < n; ++i) {
            right = i;
            // goes past repeating characters
            while (right < n && s[i] == s[right]) {
                right++;
            }
            left = i - 1;
            // check sides to see if palindrome can expand
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            int pal_len = right - left - 1;
            // set indices if new maxLength
            if (pal_len > end) {
                end = pal_len;
                start = left + 1;
            }
        }
        return s.substr(start, end);
    }
};