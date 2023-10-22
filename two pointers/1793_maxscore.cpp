class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k;
        int right = k;
        int ans = nums[k];
        int m = nums[k];
        while (left > 0 || right < n - 1) {
            // WTF?
            if ((left > 0 ? nums[left - 1] : 0) < (right < n - 1 ? nums[right + 1] : 0)) {
                right++;
                m = min(m, nums[right]);
            }
            else {
                --left;
                m = min(m, nums[left]);
            }
            ans = max(ans, m * (right - left + 1));
        }
        return ans;

        // int n = nums.size();
        // int ans = 0;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (i <= k && k <= j) {
        //             int mn = INT_MAX;
        //             for (int l = i; l <= j; ++l) {
        //                 mn = min(mn, nums[l]);
        //             }
        //             ans = max(ans, mn * (j - i + 1));
        //         }
        //     }
        // }
        // return ans;
    }
};