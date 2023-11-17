class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // return max - min of middle k elements
        sort(nums.begin(), nums.end());
        // for (auto n : nums) cout << n << ' ';
        // cout << endl;
        int ans = nums[k - 1] - nums[0];
        for (int i = k; i < nums.size(); ++i) {
            // cout << nums[i] << ' ' << nums[i - k + 1] << endl;
            ans = min(ans, nums[i] - nums[i - k + 1]);
        }
        return ans;
    }
};