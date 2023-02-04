class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int match, index;
        index = match = 0;
        if (ruleKey == "color") { ++index; }
        if (ruleKey == "name") { index += 2; }
        for (int i = 0; i < items.size(); ++i) {
            if (items[i][index] == ruleValue) {
                ++match;
            }
        }
        return match;
    }
};
