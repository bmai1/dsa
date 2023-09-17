class Solution {
public:
    int countWays(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) ++res;
        if (nums[n - 1] < n) ++res;
        for (int i = 0; i < n - 1; ++i) 
            if (nums[i] < i + 1 && nums[i + 1] > i + 1) ++res;
        return res;
    }
};