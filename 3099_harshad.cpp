class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int tmp = x;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        if (tmp % sum == 0) return sum;
        return -1;
    }
};