class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> pal;
        unordered_map<string, int> pair;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i][0] == words[i][1]) { pair[words[i]]++; }
            else { pal[words[i]]++; }
        }
        for (auto it = pal.begin(); it != pal.end(); ++it) {
            string tmp = string(1, it->first[1]) + it->first[0];
            if (pal[tmp] == it->second) { ans += 2 * it->second; }
            else { ans += 2 * min(pal[tmp], it->second); }
        }
        bool mid = false;
        for (auto it = pair.begin(); it != pair.end(); ++it) {
            if (it->second % 2 == 0) { ans += 2 * it->second; }
            else {
                // single pair in center
                if (mid == false) { ans += 2; mid = true; }
                ans += 2 * (it->second - 1);
            }
        }
        return ans;
        
        // int ans = 0;
        // unordered_map<char, int> m;
        // bool mid = false;
        // for (string word: words) {
        //     if (word[0] == word[1] && mid == false) { ans += 2; mid = true; }
        //     else {
        //         m[word[0]]++;
        //         m[word[1]]++;
        //         for (string s: words) {
        //             if (s != word) {
        //                 m[s[0]]--;
        //                 m[s[1]]--;
        //             }
        //             if (m[word[0]] == 0 && m[word[1]] == 0) { ans += 2; break; }
        //             else {
        //                 m.clear();
        //                 m[word[0]]++;
        //                 m[word[1]]++;
        //             }
        //         }
        //     }
        //     m.clear();
        // }
        // return ans;
    }
};
