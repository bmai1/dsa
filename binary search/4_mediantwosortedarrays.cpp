class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // left partition contains elements <= median
        int lo = 0, hi = n1;

        while (lo <= hi) {
            int mid1 = (lo + hi) / 2; // part index of nums1
            int mid2 = left - mid1;   // part index of nums2

            int left1  = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN; // largest on left part of nums1
            int left2  = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN; // largest on left part of nums2
            int right1 = mid1 < n1 ? nums1[mid1] : INT_MAX;         // smallest on right part of nums1
            int right2 = mid2 < n2 ? nums2[mid2] : INT_MAX;         // smallest on right part of nums2

            // valid partition 
            if (left1 <= right2 && left2 <= right1) {
                if (n % 2 == 1) return max(left1, left2);
                return ((double) (max(left1, left2) + min(right1, right2))) / 2.0;
            }
            
            if (left1 > left2) hi = mid1 - 1;
            else lo = mid1 + 1;
        }

        return -1;
    }
};
