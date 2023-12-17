class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> lastOccurrence(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, lastOccurrence[s[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};