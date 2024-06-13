class Solution {
private:
    vector<string> res;
    bool valid(string c) {
        if (c.empty() || c.size() > 3 || (c.size() != 1 && c[0] == '0')) return false;
        return stoi(c) <= 255;
    }
    void b(string s, string ip, int d, int i) {
        if (d > 3 || ip.size() > 12) return;
        if (d == 3 && valid(s.substr(i))) {
            res.push_back(ip + s.substr(i));
            return;
        }
        for (int j = i; j < i + 3 && j < s.size(); ++j) {
            if (valid(s.substr(i, j - i + 1))) {
                ip = ip + s[j] + '.';
                b(s, ip, d + 1, j + 1);
                ip.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        b(s, "", 0, 0);
        return res;
    }
};