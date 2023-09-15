class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        vector<vector<int>> v(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                v[i][c - 'a']++;
            }
        }

        for (int i = 0; i < 26; ++i) {
            string c = string(1, 'a' + i);
            int mn = INT_MAX;
            for (int j = 0; j < n; ++j) mn = min(mn, v[j][i]);
            while (mn--) ans.push_back(c);
        }

        return ans;
    }
};