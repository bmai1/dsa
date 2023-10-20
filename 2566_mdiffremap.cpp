class Solution {
public:
    int minMaxDifference(int num) {
        string mn = to_string(num), mx = mn;
        char r = mn[0];
        for (auto &c : mn) if (c == r) c = '0';
        // find next largest number not 9
        if (r == '9') {
            for (auto c : mx) {
                if (c != '9') { r = c; break; }
            }
        }
        for (auto &c : mx) if (c == r) c = '9';
        return stoi(mx) - stoi(mn);
    }
};