class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        unordered_map<char, int> row;
        for (char c : row1) row[c] = 1;
        for (char c : row2) row[c] = 2;
        for (char c : row3) row[c] = 3;

        for (auto word : words) {
            bool one_row = true;
            for (int i = 0; i < word.size() - 1; ++i) {
                if (row[tolower(word[i])] != row[tolower(word[i + 1])]) {
                    one_row = false; 
                    break;
                }
            }
            if (one_row) ans.push_back(word);
        }
        return ans;
    }
};