class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // two pointer TLE
        // if (k == 1) { return *max_element(nums.begin(), nums.end()); }
        // double ans = INT_MIN; 
        // for (int i = 0; i < nums.size() - k + 1; ++i) {
        //     double sum = 0;
        //     for (int j = i; j < i + k; ++j) {
        //         sum += nums[j];
        //     }
        //     ans = max(ans, sum / k);
        // }
        // return ans;  

        // sliding window
        double window = 0, ans = INT_MIN;
        for (int i = 0; i < k; ++i) {
            window += nums[i];
        }
        ans = max(ans, window / k);
        for (int i = k; i < nums.size(); ++i) {
            window += nums[i] - nums[i - k];
            ans = max(ans, window / k);
        }
        return ans; 
    }
};
