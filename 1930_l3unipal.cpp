class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // if find two matching characters, add number of unique characters between

        // store first and last indexes of characters
        unordered_map<char, pair<int, int>> loc;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        for (auto c : alpha) loc[c] = {-1, -1};
        for (int i = 0; i < s.size(); ++i) {
            if (loc[s[i]].first == -1) loc[s[i]].first = i;
            loc[s[i]].second = i;
        }

        int res = 0;
        unordered_set<int> u;
        for (auto [c, p] : loc) {
            // count unique char between first and last occurrence
            if (p.first < p.second) {
                for (int i = p.first + 1; i < p.second; ++i) u.insert(s[i]);
                res += u.size();
                u.clear();
            }
        }
        return res;

        // unordered_set<string> u;
        // int res = 0, n = s.size();
        // string tmp; 
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 2; j < n; ++j) {
        //         if (s[i] == s[j]) {
        //             // middle char
        //             for (int k = i + 1; k < j; ++k) {
        //                 tmp += s[i];
        //                 tmp += s[k];
        //                 tmp += s[j];
        //                 if (u.count(tmp) == 0) {
        //                     u.insert(tmp);
        //                     ++res;
        //                 }
        //                 tmp.clear();
        //             }
        //         }   
        //     }
        // }
        // return u.size(); 
    }
};