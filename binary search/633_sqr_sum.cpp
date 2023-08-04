class Solution {
public:
    bool judgeSquareSum(int c) {
        long start = 0, end = sqrt(c);
        while (start <= end) {
            long sum = pow(start, 2) + pow(end, 2);
            if (int(sum) == c) { return true; }
            if (sum < c) { start++; }
            else if (sum > c) { end--; }
        }
        return false;
    }
};
