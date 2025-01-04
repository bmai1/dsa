class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        for (int i = 0; i < word.size() - 1; ++i) {
            while (word[i] == word[i + 1]) {
                ++i;
                ++res;
            }
        }
        return res;
    }
};
