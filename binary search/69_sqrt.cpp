class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0, hi = x;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (mid * mid <= x) lo = mid + 1;
            else hi = mid;
        }
        return lo - 1; 

        // long r = x;
        // while (r * r > x) {
        //     r = (r + x / r) / 2;
        // }
        // return r;
    }
};