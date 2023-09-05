class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int total = 0, sum = 0;
        for (int n : nums) total += n;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans.push_back(nums[i]);
            total -= nums[i];
            sum += nums[i];
            if (sum > total) break;
        }
        sort(ans.rbegin(), ans.rend());
        return ans;
    }
};