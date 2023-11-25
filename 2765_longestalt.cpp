class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int res = 0, j, inc, len;
        for (int i = 0; i < nums.size(); ++i) {
            j = i, inc = 1, len = 1;
            while (j < nums.size() - 1 && nums[j] + inc == nums[j + 1]) {
                ++len; ++j;
                inc = -inc; 
            } 
            res = max(res, len);
        }
        return res > 1 ? res : -1;
    }
};