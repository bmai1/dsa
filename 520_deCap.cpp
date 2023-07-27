class Solution {
private:
    string tl(string s) { for (char &c : s) c = tolower(c); return s; }
    string tu(string s) { for (char &c : s) c = toupper(c); return s; }
public:
    bool detectCapitalUse(string word) {
        if (word == tl(word) || word == tu(word)) return true;
        for (int i = 1; i < word.size(); ++i) {
            if (isupper(word[i])) return false;
        }
        return isupper(word[0]);
    }

    int cnt = 0;
    for (char c : word) if (isupper(c)) ++cnt;
    return cnt == 0 || (cnt == 1 && isupper(word[0])) || cnt == word.size();
};
