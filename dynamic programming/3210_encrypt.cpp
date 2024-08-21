class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            res += s[(i + k) % n];
        }
        return res;
    }
};