class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k) {
            int n = word.size();
            for (int i = 0; i < n; ++i) {
                if (word[i] == 'z') word += 'a';
                else word += (word[i] + 1); 
            }
        }
        return word[k - 1];
    }
};
