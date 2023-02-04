class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dict; 
        int index = 0;
        // lower order = higher dict value
        for (char c : order) {
            dict[c] = index++;
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            int n =  min(words[i].size(), words[i + 1].size());
            // check prefixes
            int check = 0; 
            // skip duplicate
            if (words[i] == words[i + 1]) { continue; }
            for (int j = 0; j < n; ++j) {
                if (words[i][j] == words[i + 1][j]) { continue; }
                // pass case
                if (dict[words[i][j]] < dict[words[i + 1][j]]) { ++check; break; }
                if (dict[words[i][j]] > dict[words[i + 1][j]]) { return false; }
            }
            // common prefix
            if (check == 0 && words[i].size() > words[i + 1].size()) { return false; }
        } 
        return true;
    }
};
