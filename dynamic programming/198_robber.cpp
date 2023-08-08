class Solution {
private: 
    vector<int> dp;
    int helper(vector<int>& nums, int i) {
        if (i < 0) return 0;
        if (dp[i] >= 0) return dp[i];
        int res = max(helper(nums, i - 2) + nums[i], helper(nums, i - 1));
        dp[i] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return helper(nums, n - 1);
    }
};