class Solution {
public:
    int rob(vector<int>& nums) {
        // iterative bottom-up memo
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[n];


        // find max sum of elements without robbing adjacent houses
        // should not be every other house, the robbing house has to be higher than sum of two adjacent sides

        // base case
        if (nums.size() == 0) { return 0; }
        int prev1 = 0, prev2 = 0;
        for (int num : nums) {
            int t = prev1; 
            prev1 = max(prev2 + num, prev1);
            prev2 = t;
        }
        return prev1;
    }
};
