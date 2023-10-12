/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mArr) {
        // find peak, binary search both ranges
        int peak = 0, end = mArr.length() - 1, mid;
        while (peak < end) {
            mid = peak + (end - peak) / 2;
            if (mArr.get(mid) > mArr.get(mid + 1)) end = mid;
            else peak = mid + 1;
        }

        // search left of peak
        int lo = 0, hi = peak, found = -1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int tmp = mArr.get(mid);
            if (tmp == target) { found = mid; break; }
            if (tmp < target) lo = mid + 1;
            else hi = mid - 1;
        }
        if (found != -1) return found;

        // search right of peak
        lo = peak + 1, hi = mArr.length() - 1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int tmp = mArr.get(mid);
            if (tmp == target) return mid;
            if (tmp > target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};