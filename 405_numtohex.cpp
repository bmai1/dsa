class Solution {
public:
    string toHex(int num) {
        string hex = "0123456789abcdef";
        if (num == 0) return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) {
            result = hex[(num & 0xf)] + result;
            num >>= 4;
        }
        return result; 
    }
};