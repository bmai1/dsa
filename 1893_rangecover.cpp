class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool found;
        for (int i = left; i <= right; ++i) {
            found = false;
            for (auto r : ranges) {
                if (r[0] <= i && i <= r[1]) { 
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};