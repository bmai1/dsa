class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int ans = 0;
        unordered_map<int, int> m;
        for (char c : s) m[c]++;
        while (true) {
            bool enough = true;
            for (auto c : target) {
                if (m[c]-- == 0) { enough = false; break; }
            }
            if (enough) ++ans;
            else break;
        }
        return ans;
    }
};