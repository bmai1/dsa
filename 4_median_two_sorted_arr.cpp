class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // merge arrays then sort
        for (auto n : nums2) { nums1.push_back(n); }
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        // if even amount of numbers, return average of middle two numbers
        // else if odd, return middle number
        return n % 2 == 0 ? (nums1[(n / 2) - 1] + nums1[n / 2]) / 2.0 : (nums1[((n + 1) / 2) - 1]);
    }
};
