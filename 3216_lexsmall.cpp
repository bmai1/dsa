class Solution {
public:
    string getSmallestString(string s) {
        // cout << ("43502" < "43520") << endl;
        // return "";

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] > s[i + 1] && (s[i] - '0') % 2 == (s[i + 1] - '0') % 2) {
                swap(s[i], s[i + 1]);
                return s;
            }
        }
        return "";
    }
};