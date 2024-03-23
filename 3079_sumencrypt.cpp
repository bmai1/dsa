class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            int m = 0, i = 0;
            while (n) {
                m = max(m, n % 10);
                n /= 10;
                ++i;
            }
            while (i--) sum += m * pow(10, i);
        }
        return sum;
    }
};