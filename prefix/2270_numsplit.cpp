class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> sums(n + 1);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            cnt += (sums[i + 1] >= sums[n] - sums[i + 1]);
        }
        return cnt;
    }
};
