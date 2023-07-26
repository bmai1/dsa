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
};