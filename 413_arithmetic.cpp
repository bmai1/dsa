class Solution {
private:
    bool arithmetic(vector<int>& nums) {
        int d = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] != d) { return false; }
        }
        return true;
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        // generate subarrays
        for (int i = 0; i < n; ++i) {
            vector<int> subarray;
            for (int j = i; j < n; ++j) {
                subarray.push_back(nums[j]);
                if (subarray.size() >= 3 && arithmetic(subarray) == true) { ans++; }
            }
        }
        return ans;
    }
};
