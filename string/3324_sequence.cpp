class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        string curr; 
        for (char c : target) {
            curr += 'a';
            while (curr.back() != c) {
                res.push_back(curr);
                curr.back() = curr.back() + 1;
            }
            res.push_back(curr);
        }
        return res;
    }
};