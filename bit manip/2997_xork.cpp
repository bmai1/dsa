class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // find array xor
        int res = 0;
        for (int n : nums) res ^= n;

        // find bit difference (hamming distance)

        int x = res ^ k, cnt = 0;
        while (x) {
            cnt += x & 1;
            x >>= 1;
        }
        return cnt;

        // return __builtin_popcount(res ^ k);
    }
};