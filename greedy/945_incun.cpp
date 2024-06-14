class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            int d = nums[i - 1] - nums[i];
            if (d >= 0) {
                res += d + 1;
                nums[i] += d + 1;
            }
        }
        return res;
    }
};