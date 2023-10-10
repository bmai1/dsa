class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> m; 
        for (auto word : words) {
            for (auto c : word) ++m[c];
        }
        int n = words.size();
        for (auto it : m) {
            // cout << it.first << ' ' << it.second << endl;
            if (it.second % n) return false;
        }
        return true;
    }
};