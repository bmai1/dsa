class Solution {
public:
    int smallestNumber(int n) {
        // while (true) {
        //     int x = n; 
        //     while (x) {
        //         if ((x & 1) == 0) {
        //             break;
        //         }
        //         x >>= 1;
        //     }
        //     if (x == 0) return n;
        //     ++n;
        // }
        // return -1;

        int res = 1; 
        while (res < n) {
            res = res * 2 + 1;
        }
        return res;
    }
};
