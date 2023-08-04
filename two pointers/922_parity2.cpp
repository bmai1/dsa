class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        // for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2) {
        //     while (i < n && nums[i] % 2 == 0) i += 2;
        //     while (j < n && nums[j] % 2 == 1) j += 2;
        //     if (i < n) swap(nums[i], nums[j]);
        // }
        // return nums;

        int even = 0, odd = 1;
        while (even < n && odd < n) {
            if (nums[even] % 2 != 0 && nums[odd] % 2 == 0) {
                swap(nums[even], nums[odd]);
            }
            if (nums[even] % 2 == 0) even += 2;
            if (nums[odd] % 2 != 0) odd += 2;
        }
        return nums;
    }
};