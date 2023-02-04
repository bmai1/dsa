class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for (int i = 0; i < s.length(); ++i) {
            // check for '#' in advance
            if (i + 2 < s.length() && s[i + 2] == '#') {
                // first digit is 10s, second digit is ones (minus 1 because index is 1 ahead)
                ans += 'a' + ((s[i] - '0') * 10 + s[i + 1] - '1');
                // skip 2 index
                i += 2;
            }
            // no hash
            else { ans += 'a' + (s[i] - '1'); }
        }
        return ans;
    }
};
