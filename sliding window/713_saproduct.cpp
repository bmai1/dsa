class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size(), res = 0, start = 0, end = 0, product = 1;
        for (; end < n; ++end) {
            product *= nums[end];
            while (product >= k) {
                product /= nums[start++];
            }
            res += end - start + 1;
        }
        return res;
    }
};