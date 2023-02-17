class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // m > n
        int m = s.length(), n = p.length();
        if (m < n) { return {}; }
        // keep track of letter, window
        vector<int> freq(26, 0), window(26, 0), ans;
        for (int i = 0; i < n; ++i) {
            freq[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        // initial case
        if (freq == window) { ans.push_back(0); }
        // two pointers
        for (int j = n; j < m; ++j) {
            window[s[j - n] - 'a']--;
            window[s[j] - 'a']++;
            // +1 
            if (freq == window) { ans.push_back(j - n + 1); }
        }
        return ans; 
    }
};
