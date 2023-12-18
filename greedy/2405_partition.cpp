class Solution {
public:
    int partitionString(string s) {
        int res = 1;
        unordered_map<char, int> m;
        for (char c : s) {
            if (++m[c] == 2) {
                m.clear();
                ++m[c];
                ++res;
            }
        }
        return res; 
    }
};