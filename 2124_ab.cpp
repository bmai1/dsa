class Solution {
public:
    bool checkString(string s) {
        bool b = false; 
        for (char c : s) {
            if (b && c == 'a') return false;
            if (c == 'b') b = true;
        }
        return true;
    }
};