class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26);
        int res = 0;
        for (char c : word) f[c - 'a']++;
        sort(f.rbegin(), f.rend());
        for (int i = 0; i < 26; ++i) {
            res += f[i] * ((i / 8) + 1);
        }
        return res;
        
        // unordered_map<char, int> m;
        // for (char c : word) m[c]++;
         
        // int res = 0, pushes = 1, cnt = 0;
        // while (!m.empty()) {
        //     int mx = INT_MIN;
        //     int key;
        //     for (auto it : m) {
        //         if (it.second > mx) {
        //             key = it.first;
        //             mx = it.second;
        //         }
        //     }
        //     res += m[key] * pushes;
        //     m.erase(key);
        //     // only 8 keys can be mapped
        //     if (++cnt == 8) {
        //         ++pushes;
        //         cnt = 0;
        //     }
        // }

        // return res;
    }
};