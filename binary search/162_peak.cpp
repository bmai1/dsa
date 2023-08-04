class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1|| nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        // for (int i = 1;  i < nums.size() - 1; ++i) {
        //     if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
        // }
        // return -1;

        int lo = 1, hi = n - 2;
        while (lo <= hi) {
            // when lo == hi, a peak has been found
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            // where did these conditionals come from?
            else if (nums[mid] < nums[mid - 1]) hi = mid - 1;
            else if (nums[mid] < nums[mid + 1]) lo = mid + 1;
        }
        return -1;
    }
};