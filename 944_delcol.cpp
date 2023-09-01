class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int del = 0;
        for (int col = 0; col < strs[0].size(); ++col) {
            char prev = strs[0][col];
            for (int row = 1; row < strs.size(); ++row) {
                if (strs[row][col] < prev) { ++del; break; }
                prev = strs[row][col];
            }
        }
        return del;
    }
};