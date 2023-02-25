class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) { return {}; }
        vector<string> ans;
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        ans.push_back("");
        for (auto d: digits) {
            vector<string> tmp;
            for (auto c: pad[d - '0']) {
                for (auto s: ans) {
                    tmp.push_back(s + c);
                }
            }
            ans.swap(tmp);
        }
        return ans; 
    }

};
