class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pre; 
        int n = nums.size(), sum = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum == k) ++ans;
            if (pre.find(sum - k) != pre.end()) ans += pre[sum - k];
            pre[sum]++;
        }
        return ans;
    }
};