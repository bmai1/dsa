class Solution {
public:
    string intToRoman(int num) {
        // O(N)
        // string ans; 
        // int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        // string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        // for (int i = 0; num != 0; ++i) {
        //     while (num >= val[i]) {
        //         num -= val[i];
        //         ans += sym[i];
        //     }
        // }
        // return ans;

        string one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hun[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ths[] = {"", "M", "MM", "MMM"};

        return ths[num / 1000] + hun[(num % 1000) / 100] + ten[(num % 100) / 10] + one[num % 10];
    }
};
