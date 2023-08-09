class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0; 
        while (a != 0 || b != 0 || c != 0) {
            if (!(c & 1)) {
                // swap 1s to match 0 at c's end
                ans += (a & 1) + (b & 1);
            }
            else if (!(a & 1) && !(b & 1)) ++ans; // ensure at least one set bit
            a >>= 1, b >>= 1, c >>= 1; 
        }
        return ans; 
    }
};