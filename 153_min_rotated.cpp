class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                return nums[i + 1];
            }
        }
        return min;
    }
};
