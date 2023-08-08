class Solution {
    vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void backtrack(string ndigits, string combination) {
        if (ndigits.empty()) {
            ans.push_back(combination);
            return;
        }
        string key = m[ndigits[0] - '0'];
        for (char c : key) {
            backtrack(ndigits.substr(1), combination + c);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtrack(digits, "");
        return ans;
    
        // if (digits.empty()) { return {}; }
        // vector<string> ans;
        // vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        // ans.push_back("");
        // for (auto d: digits) {
        //     vector<string> tmp;
        //     for (auto c: pad[d - '0']) {
        //         for (auto s: ans) {
        //             tmp.push_back(s + c);
        //         }
        //     }
        //     ans.swap(tmp);
        // }
        // return ans; 
    }
};