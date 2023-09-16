class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0, i = 0;
        while (n) {
            ans += i++ % 2 ? n % 10 : -(n % 10);
            n /= 10;
        }
        return ans * (i % 2 ? -1 : 1);
    }
};