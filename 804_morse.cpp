class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> alpha = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for (auto word : words) {
            string morse;
            for (auto c : word) {
                morse += alpha[c - 'a'];
            }
            s.insert(morse);
        }
        return s.size();
    }
};
