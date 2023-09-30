class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed[0] != name[0]) return false;
        int i = 0, j = 0;
        for (; i < name.size() && j < typed.size(); ++i, ++j) {
            while (j < typed.size() && typed[j] != name[i]) {
                if (j > 0 && typed[j - 1] != typed[j]) return false;
                ++j;
            }
            if (j == typed.size()) return false; // no match in typed
        }
        // check extraneous letters
        for (; j < typed.size(); ++j) {
            if (typed[j] != name.back()) return false;
        }
        return i == name.size() && j == typed.size();

        int i = 0, n = name.size(), t = typed.size();
        for (int j = 0; j < typed.size(); ++j) {
            if (i < n && name[i] == typed[j]) ++i;
            else if (!j || typed[j] != typed[j - 1]) return false;
        }
        return i == n;
    }
};