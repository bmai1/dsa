class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int o = nums[i];
            for (int j = i; j < n; ++j) {
                o |= nums[j];
                if (o >= k) {
                    res = min(res, j - i + 1);
                    break;
                }
            } 
        }
        return res == INT_MAX ? -1 : res;
    }
};
