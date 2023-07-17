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
                bits += j & 1;
                j >>= 1;
            }
            ans.push_back(bits);
        }
        return ans;
    }
};