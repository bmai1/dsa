class Solution {
public:
    int countEven(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int sum = 0, t = i;
            while (t) {
                sum += t % 10;
                t /= 10;
            }
            cnt += !(sum % 2);
        }
        return cnt;
    }
};