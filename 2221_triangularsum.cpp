class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> next;
        while (nums.size() != 1) {
            for (int i = 0; i < nums.size() - 1; ++i) {
                next.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = next;
            next.clear();
        }
        return nums[0];
    }
};