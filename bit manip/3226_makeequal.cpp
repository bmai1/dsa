class Solution {
public:
    int minChanges(int n, int k) {
        if (k > n) return -1;
        int cnt = 0;
        while (n) {
            int kb = k & 1;
            int nb = n & 1;
            if (kb == 1 && nb == 0) return -1;
            cnt += kb == 0 && nb == 1;
            k >>= 1;
            n >>= 1;
        }
        return cnt;

        // k ^= n;
        // int cnt = __builtin_popcount(k);
        // k &= n;
        // return cnt == __builtin_popcount(k) ? cnt : -1;
    }
};
