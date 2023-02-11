class Solution {
public:
    int longestPalindrome(string s) {
        if (s.length() == 1) { return 1; }
        unordered_map<char, int> m; 
        for (char c: s) { m[c]++; }
        bool one = true; 
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            // inherently palindromic so don't need to check for center
            if (it->second % 2 == 0) { 
                ans += it->second; 
            }
            else {
                // fill middle element for odd count of characters
                if (one == true) {
                    one = false;
                    ans += it->second;
                }
                // if middle is taken, then add max number of palindromic chars
                else {
                    ans += it->second - 1;
                }
            }
        }
        return ans; 
    }
};
