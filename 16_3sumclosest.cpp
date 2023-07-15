class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int sum, j, k;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            j = i + 1;
            k = nums.size() - 1;
            
            while (j < k) {
                if (sum == target) return sum;
                sum = nums[i] + nums[j] + nums[k];
                if (sum > target) --k;
                else ++j;
                
                // difference is absolute value
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
            }
        }
        return closest;
    }
};