class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int prev[26]{}; // last index (start from 1)
        for (int i = 0; i < s.size(); ++i) {
            if (prev[s[i] - 'a'] && i - prev[s[i] - 'a'] != distance[s[i] - 'a']) return false;
            prev[s[i] - 'a'] = i + 1;
        }
        return true;
    }
};