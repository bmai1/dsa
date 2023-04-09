class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size(), left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            right -= nums[i];
            ans[i] = abs(left - right);
            left += nums[i];
        }
        return ans;
    }
};
