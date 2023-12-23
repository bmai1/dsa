class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0, f[26]{};
        for (int i = 0; i < s.size(); ++i) {
            f[s[i] - 'a']++;
            f[t[i] - 'a']--;
        } 
        for (auto n : f) res += abs(n);
        // odd switches round up
        return (res + 1) / 2;
    }
};