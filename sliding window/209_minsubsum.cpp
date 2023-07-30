class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // TLE
        // int minL = INT_MAX;
        // for (int i = 0; i < nums.size(); ++i) {
        //     int sum = 0;
        //     for (int j = i; j < nums.size(); ++j) {
        //         sum += nums[j];
        //         if (sum >= target) {
        //             minL = min(minL, j - i + 1);
        //         } 
        //     }
        // }
        // return minL == INT_MAX ? 0 : minL;

        int n = nums.size(), sum = 0, left = 0, minL = INT_MAX;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum >= target) {
                minL = min(minL, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return minL == INT_MAX ? 0 : minL;
    }
};
