class Solution {
public:
    char findTheDifference(string s, string t) {
        // t is longer
        unordered_map<char, int> first;
        unordered_map<char, int> second; 
        
        // count occurrences
        for (int i = 0; i < t.length(); ++i) {
            first[s[i]]++;
            second[t[i]]++;
        }
        // find char not in common
        for (char c : t) {
            if (first[c] != second[c]) {
                return c; 
            }
        }
        return NULL;
    }
};
