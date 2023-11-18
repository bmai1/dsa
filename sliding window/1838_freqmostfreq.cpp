class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // brust force!
        // sort(nums.begin(), nums.end());

        // int res = 1, curr, freq, ops, diff;
        // for (int i = 1; i < nums.size(); ++i) {
        //     curr = nums[i];
        //     freq = 1;
        //     ops = k;
        //     for (int j = i - 1; j >= 0; --j) {
        //         diff = curr - nums[j];
        //         if (ops - diff >= 0) {
        //             ops -= diff;
        //             ++freq;
        //         } 
        //         else break;
        //     }
        //     res = max(res, freq);
        // }
        // return res;

        sort(nums.begin(), nums.end());
        long long res = 1, left = 0, ops = 0;
        for (int right = 1; right < nums.size(); ++right) {
            ops += (nums[right] - nums[right - 1]) * (right - left);
            // adjust window size
            while (ops > k) {
                // update window state with left
                ops -= nums[right] - nums[left];
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};