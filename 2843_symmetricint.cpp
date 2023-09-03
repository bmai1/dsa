class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0; 
        for (int i = low; i <= high; ++i) {
            int n = to_string(i).size();
            if (n % 2) continue;
            int s1 = 0, s2 = 0, num = i;
            for (int j = 0; j < n / 2; ++j) {
                s1 += num % 10;
                num /= 10;
            }
            while (num) { s2 += num % 10; num /= 10; }
            if (s1 == s2) ++ans;
        }
        return ans;
    }
};