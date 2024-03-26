class Solution {
public:
    int maximumLengthSubstring(string s) {
        int mx = 2, curr = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (++m[s[j]] > 2) break;
                else ++curr;
            }
            mx = max(mx, curr); 
            m.clear();
            curr = 0;
        }
        return mx;
    }
};