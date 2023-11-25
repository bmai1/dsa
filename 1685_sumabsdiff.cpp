class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0), n = nums.size(); 
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = i * nums[i] - left + right - (n - i) * nums[i];
            left += nums[i];
            right -= nums[i];
        }
        return res;
    }
};