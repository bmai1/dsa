class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        int n = a + b + c, x = 0, y = 0, z = 0;
        for (int i = 0; i < n; ++i) {
            int m = max(a, max(b, c));
            if ((a == m && x != 2) || (y == 2 && a > 0) || (z == 2 && a > 0)) {
                res += "a";
                ++x, --a, y = 0, z = 0;
            }
            else if ((b == m && y != 2) || (x == 2 && b > 0) || (z == 2 && b > 0)) {
                res += "b";
                ++y, --b, x = 0, z = 0;
            }
            else if ((c == m && z != 2) || (x == 2 && c > 0) || (y == 2 && c > 0)) {
                res += "c";
                ++z, --c, x = 0, y = 0;
            }
        }
        return res;
    }
};