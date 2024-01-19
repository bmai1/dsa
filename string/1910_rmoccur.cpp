class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int n = part.size();
        for (char c : s) {
            res += c;
            if (res.size() >= n && res.substr(res.size() - n, n) == part) {
                for (int i = 0; i < n; ++i) res.pop_back();
            }
        }
        return res;
    }
};