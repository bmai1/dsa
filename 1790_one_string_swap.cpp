class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) { return true; }
        if (s1.length() == 1 || s1.length() == 2) { return s1 == s2; }
        // count incorrect chars
        int c = 0, index; 
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) { 
                // seen first incorrect
                if (c == 1) {
                    // swap characters
                    char tmp = s1[index];
                    s1[index] = s1[i];
                    s1[i] = tmp;
                    return s1 == s2;
                }
                ++c; 
                // save index of incorrect char
                index = i;
            }
        }
        return false; 
    }
};
