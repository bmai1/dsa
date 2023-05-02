class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_map<char, int> a;
        for (char c : allowed) { a[c]++; }
        for (string word : words) {
            bool valid = true;
            for (char c : word) {
                if (a[c] == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid == true) ++ans;
        }
        return ans;
    }
};
