class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        // stl
        for (int i = 0; i <= n; ++i) {
            bitset<sizeof(int) * 8> binary(i);
            ans.push_back(binary.count());
        }
        // bitwise operator
        for (int i = 0; i <= n; ++i) {
            int bits = 0, j = i;
            while (j != 0) {
                // bitwise AND, only returns 1 if both 1, else 0
                // this line increments bits whenever the last bit is one
                // and converts the rest of the ones in j to zeroes.
                bits += j & 1;
                // right shift, divides an integer (left) by a power of 2 (right)
                // a >>= b -> a / 2^b
                j >>= 1;
            }
            ans.push_back(bits);
        }
        return ans;
    }
};