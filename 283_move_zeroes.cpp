class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int n = 0, s = 0;
        // while (n < nums.size()) {
        //     if (nums[n]) {
        //         swap(nums[s++], nums[n++]);
        //     }
        //     else ++n;
        // }

        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (; j < nums.size(); ++j) {
            nums[j] = 0;
        }
    }
};
