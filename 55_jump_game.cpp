class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        // start from end (bottom-up)
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= nums[i]; ++j) {
                if (dp[i + j] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        // true if went from end to start
        return dp[0]; 

        // // greedy 
        // int n = nums.size(), i = 0, j; 
        // for (j = 0; i < n && i <= j; ++i) {
        //     j = max(i + nums[i], j);
        // }
        // return i == n;
    }
};
