class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        for (auto n : nums) {
            mn = min(mn, n);
            mx = max(mx, n);
        }
        for (auto n : nums) {
            if (mn < n && n < mx) return n;
        }
        return -1;
    }
};