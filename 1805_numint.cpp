class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        string n, z; // n skips leading zeroes, z holds only zero
        bool zflag = true;
        for (auto c : word) {
            if (isdigit(c)) {
                if (zflag && c == '0') z += c;
                else {
                    z.clear();
                    // not a valid 0
                    zflag = false;
                }
                if (c != '0' || !n.empty()) n += c;
            } 
            else {
                if (!n.empty()) {
                    s.insert(n);
                    n.clear();
                }
                if (!z.empty()) {
                    s.insert("0");
                    z.clear();
                }
                // re-enable zero tracking
                zflag = true;
            }
        }
        if (!n.empty()) s.insert(n);
        if (!z.empty()) s.insert("0");
        return s.size();
    }
};