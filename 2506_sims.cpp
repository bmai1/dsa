class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        unordered_map<string, int> m;
        for (auto &word : words) {
            string chars(26, '0');
            for (char c : word) {
                chars[c - 'a'] = '1';
            }
            cnt += m[chars];
            m[chars]++;
        }
        return cnt;
    }
};