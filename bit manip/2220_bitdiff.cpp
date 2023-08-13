class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);

        int cnt = 0;
        while (max(start, goal) != 0) {
            cnt += (start & 1) ^ (goal & 1);
            start >>= 1, goal >>= 1;
        }
        return cnt;
    }
};