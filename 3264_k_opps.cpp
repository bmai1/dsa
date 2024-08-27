class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int j, m = INT_MAX;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < m) {
                    j = i;
                    m = nums[i];
                }
            }
            nums[j] = m * multiplier;
        }
        return nums;
    }
};