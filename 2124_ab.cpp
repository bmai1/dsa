class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
        
        bool b = false; 
        for (char c : s) {
            if (b && c == 'a') return false;
            if (c == 'b') b = true;
        }
        return true;
    }
};