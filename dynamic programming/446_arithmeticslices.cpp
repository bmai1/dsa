class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<unordered_map<long long, int>> dp(n); 
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = (long long) nums[i] - nums[j];
                int cnt = dp[j].count(d) ? dp[j][d] : 0;
                dp[i][d] += cnt + 1;
                res += cnt;
            }
        }
        return res;
    }
};