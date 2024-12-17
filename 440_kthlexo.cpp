class Solution {
private: 
    int p_count(int n, int p) {
        long long curr = p, next = p + 1;
        int cnt = 0;
        while (curr <= n) {
            // what the hell
            cnt += (int) (min(n + 1LL, next) - curr);
            curr *= 10;
            next *= 10;
        }
        return cnt;
    }
public:
    int findKthNumber(int n, int k) {
        int p = 1;
        --k;

        while (k) {
            int cnt = p_count(n, p);
            if (cnt <= k) {
                ++p;
                k -= cnt;
            }
            else {
                p *= 10;
                --k;
            }
        }
        return p;
    }
};