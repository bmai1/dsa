class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string lp; 
        for (char c : licensePlate) if (isalpha(c)) lp += tolower(c);
        int mn = INT_MAX;
        vector<string> cmpl;
        unordered_map<char, int> cnt;
        for (auto word : words) {
            bool valid = true;
            for (char c : word) ++cnt[c];
            for (char c : lp) --cnt[c];
            for (char c : lp) {
                if (cnt[c] < 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                int n = word.size();
                if (n < mn) {
                    cmpl.clear();
                    cmpl.push_back(word);
                    mn = n;
                }
                else if (n == mn) cmpl.push_back(word); 
            }
            cnt.clear();
        }
        for (auto word : words) {
            for (auto c_word : cmpl) {
                if (c_word == word) return c_word;
            }
        }
        return "this problem is retarded";
    }
};