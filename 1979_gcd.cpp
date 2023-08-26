class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
        // if (b == 0) return a;
        // return gcd(b, a % b);
    }
public:
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        for (auto n : nums) {
            mn = min(mn, n);
            mx = max(mx, n);
        }
        return gcd(mn, mx);
    }
};