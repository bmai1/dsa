class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int l = 0, r = std::accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n - 1; ++i) {
            l += nums[i];
            r -= nums[i];
            cnt += (l - r) % 2 == 0;
        }
        return cnt;
    }
};
