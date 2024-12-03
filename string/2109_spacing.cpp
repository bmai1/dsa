class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        for (int i = 0; i < spaces.size(); ++i) {
            spaces[i] += i;
        }
        int n = s.size() + spaces.size();
        vector<char> res(n);
        int i = 0, j = 0;
        for (int k = 0; k < n; ++k) {
            if (j < spaces.size() && spaces[j] == k) {
                res[k] = ' ';
                ++j;
            }
            else {
                res[k] = s[i++];
            }
        }
        return string(res.begin(), res.end());
    }
};