class Solution {
public:
    vector<int> evenOddBit(int n) {
        int e = 0, o = 0, i = 0;
        while (n) {
            if (i == 0 || !(i % 2)) e += n & 1;
            else o += n & 1;
            n >>= 1; ++i;
        }
        return {e, o};
    }
};