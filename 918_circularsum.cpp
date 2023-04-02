class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // subtract min subarray from total
        // Kadane's Algorithm

        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for (int n: nums) {
            total += n;
            curMax = max(curMax + n, n);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + n, n);
            minSum = min(minSum, curMin);
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
