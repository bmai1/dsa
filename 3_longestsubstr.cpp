class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int length = 0, index = 0, max = 1;
        string c;
        for (int i = 0; i < s.length(); ++i) {
            if (c.find(s[i]) == string::npos) {
                c += s[i];
                ++length;
            }
            else {
                c.clear();
                i = ++index;
                c += s[i];
                length = 1;
            }
            if (length > max) max = length;
        }  
        return max;
    }
};
