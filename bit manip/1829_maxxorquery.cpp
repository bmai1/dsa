class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res;
        int n = nums.size(), mx = pow(2, maximumBit) - 1, x = 0;
        for (int i = 0; i < n; ++i) {
            x ^= nums[i];
        }
        for (int i = 0; i < n; ++i) {
            res.push_back(mx ^ x);
            x ^= nums[n - 1 - i]; // remove from back
        }
        return res;

        // TLE
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int m = 0, ans = -1;
            for (int j = 0; j < pow(2, maximumBit); ++j) {
                int curr = j;
                for (int k = 0; k < nums.size(); ++k) {
                    curr ^= nums[k];
                }
                if (m < curr) {
                    m = curr;
                    ans = j;
                }
            }
            res.push_back(ans);
            nums.pop_back();
        }
        return res;
    }
};