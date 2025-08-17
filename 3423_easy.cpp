class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            res = max(res, abs(nums[i] - nums[i + 1]));
        }
        return max(res, abs(nums[0] - nums[n - 1]));
    }
};
