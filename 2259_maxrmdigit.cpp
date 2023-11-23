class Solution {
public:
    string removeDigit(string n, char digit) {
        string res = "";
        for (int i = 0; i < n.size(); ++i) {
            if (n[i] == digit) {
                // cout << n.substr(0, i) << endl;
                // cout << n.substr(i + 1) << endl;
                res = max(res, n.substr(0, i) + n.substr(i + 1));
            }
        }
        return res;
    }
};