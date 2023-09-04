class Solution {
public:
    bool digitCount(string num) {
        // unordered_map<char, int> m;
        // for (char c : num) ++m[c];
        // for (int i = 0; i < num.size(); ++i) 
        //     if (m[i + '0'] != num[i] - '0') return false;
        // return true;

        int cnt[10]{};
        for (char c : num) ++cnt[c - '0'];
        for (int i = 0; i < num.size(); ++i)
            if (cnt[i] != num[i] - '0') return false;
        return true;
    }
};