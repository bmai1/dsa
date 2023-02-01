class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        string ans;
        // alternate between chars of two strings
        for (int i = 0; i < min(l1, l2); ++i) {
            ans += word1[i];
            ans += word2[i];
        }
        // appending end of longer string
        if (l1 > l2) {
            ans += word1.substr(l2, l1 - l2);
        }
        else if (l1 < l2) {
            ans += word2.substr(l1, l2 - l1);
        }
        return ans;
    }
};
