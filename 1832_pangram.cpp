class Solution {
public:
    bool checkIfPangram(string sentence) {
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        bool check = true;
        for (int i = 0; i < 26; ++i) {
            if (sentence.find(alpha[i]) == string::npos) {
                check = false;
            }
        }
        return check;
    }
};
