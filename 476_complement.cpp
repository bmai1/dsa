class Solution {
public:
    int findComplement(int num) {
        bitset<32> b(num);
        string s = b.to_string();
        int i = 0;
        while (s[i] == '0') ++i;
        for (i; i < s.size(); ++i) {
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        return stoi(s, nullptr, 2);
    }

    unsigned mask = ~0; // ~ (bitwise NOT) represents complement of 0 (sequence of 1s in binary)
    // first we need to move to the first occurence of 1 bit otherwise it flips leading 0s in 32 bit integer
    while (num & mask) mask <<= 1; // & bitwise AND to <<= (left shift equals) by 1
    return ~mask & ~num; // mask shows where first 1 starts and complement of num with ~
};