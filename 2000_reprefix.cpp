class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans;
        int i = 0, n = word.size(); 
        while (i < n && word[i++] != ch) if (i == n - 1 && word[i] != ch) return word;
        for (int j = i - 1; j >= 0; --j) ans += word[j]; 
        for (; i < n; ++i) ans += word[i];
        return ans;
    }
};