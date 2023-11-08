class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums.push_back(nums[i]);
        }
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                res = n - i - 1;
                // check if remaining increasing
                for (int j = i + 1; j < i + n; ++j) {
                    if (nums[j] > nums[j + 1]) return -1;
                }
            }
        }
        return res;
    }
};