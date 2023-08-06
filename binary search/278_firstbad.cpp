// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;

        // int lo = 0, hi = n;
        // while (hi - lo > 1) {
        //     // instead of (lo + hi) / 2
        //     int mid = lo + ((hi - lo) / 2);
        //     if (isBadVersion(mid)) { hi = mid; }
        //     else { lo = mid; }
        // }
        // return hi;
    }
};