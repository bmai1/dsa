class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size() && j < i + r; ++j) {
                sum += nums[j];
                if (sum > 0 && j >= i + l - 1) {
                    res = min(res, sum);
                }
            } 
        }
        return res == INT_MAX ? -1 : res;
    }
};
