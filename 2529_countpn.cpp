class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // int p = 0, n = 0;
        // for (int num : nums) {
        //     p += num > 0;
        //     n += num < 0;
        // }
        // return max(p, n);
        
        int n = nums.size(), lo = 0, hi = n - 1;
        if (nums[0] > 0 || nums[n - 1] < 0) return n;
        // find turning point
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > 0) hi = mid;
            // find edge of zeroes
            else if (nums[mid] == 0) {
                lo = mid, hi = mid; 
                while (lo >= 0 && nums[lo] == 0) --lo;
                while (hi < n && nums[hi] == 0) ++hi;
                return max(lo + 1, n - hi);
            }
            else lo = mid + 1;
        }
        // cout << lo << ' ' << hi << endl;
        return max(lo, n - hi);
    }
};