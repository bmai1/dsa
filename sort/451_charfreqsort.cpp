class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        vector<pair<int, char>> v;
        for (char c : s) m[c]++;
        
        for (auto &it : m) {
            // reverse order to sort without lambda
            v.push_back({it.second, it.first});
        }

        sort(v.rbegin(), v.rend());

        string res;
        for (auto &p : v) {
            for (int i = 0; i < p.first; ++i) {
                res += p.second;
            }
        }
        return res;
    }
};