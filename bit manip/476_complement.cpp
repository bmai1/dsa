class Solution {
public:
    int findComplement(int n) {
        int c = 1;
        while (c < n) c = (c << 1) + 1; 
        return n ^ c;
    }
};