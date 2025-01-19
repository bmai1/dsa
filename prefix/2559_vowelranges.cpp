class Solution {
private:
    bool v(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res;

        int n = words.size();
        vector<int> cnts(n);
        cnts[0] = v(words[0].front()) && v(words[0].back());

        for (int i = 1; i < n; ++i) {
            cnts[i] = cnts[i - 1] + (v(words[i].front()) && v(words[i].back()));
        }

        for (auto q : queries) {
            if (q[0] == 0) res.push_back(cnts[q[1]]);
            else res.push_back(cnts[q[1]] - cnts[q[0] - 1]);
        }
        
        return res;
    }
};
