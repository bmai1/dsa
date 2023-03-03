class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // TLE
        // int max = 0; 
        // for (int i = 0; i < nums1.size(); ++i) {
        //     for (int j = 0; j < nums2.size(); ++j) {
        //         if (i <= j && nums1[i] <= nums2[j] && j - i > max) { max = j - i; }
        //     }
        // }
        // return max;

        reverse(nums2.begin(), nums2.end());
        int ans = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            // first element greater than or equal to nums1[i]
            auto it = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            int j = nums2.size() - 1 - it; 
            if (i <= j) { ans = max(ans, j - i); }
        }
        return ans;
    }
};
