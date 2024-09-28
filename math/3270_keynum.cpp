class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        // int a = 1000 * min(num1 / 1000, min(num2 / 1000, num3 / 1000));
        // int b = 100 * min((num1 / 100) % 10, min((num2 / 100) % 10, (num3 / 100) % 10));
        // int c = 10 * min((num1 / 10) % 10, min((num2 / 10) % 10, (num3 / 10) % 10));
        // int d = 1 * min((num1 / 1) % 10, min((num2 / 1) % 10, (num3 / 1) % 10));
        // return a + b + c + d;

        int key = 0, div = 1e3;
        for (int i = 0; i < 4; ++i) {
            key = key * 10 + min({ num1 / div, num2 / div, num3 / div });
            num1 %= div;
            num2 %= div;
            num3 %= div;
            div /= 10;
        }
        return key;
    }
};