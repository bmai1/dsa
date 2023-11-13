class Solution {
    bool isV(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string sortVowels(string s) {
        string inord_v;
        for (auto &c : s) if (isV(c)) { 
            inord_v += c;
            c = '1';
        }

        sort(inord_v.begin(), inord_v.end());
        int i = 0;
        for (auto &c : s) if (c == '1') c = inord_v[i++];
        return s;
    }
};