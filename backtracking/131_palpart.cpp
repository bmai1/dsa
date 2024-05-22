class Solution {
private: 
    vector<vector<string>> res;
    bool isPal(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return s == r;
    }
    
    void part(string s, int start, vector<string>& p) {
        if (start == s.size()) {
            res.push_back(p);
            return;
        }

        string curr = "";
        for (int i = start; i < s.size(); ++i) {
            curr = s.substr(start, i - start + 1);
            if (isPal(curr)) {
                p.push_back(curr);
                part(s, i + 1, p);
                p.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> p;
        part(s, 0, p);
        return res;
    }
};