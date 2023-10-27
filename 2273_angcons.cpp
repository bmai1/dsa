class Solution {
private:
    bool anagram(string a, string b) {
        if (a.size() != b.size()) return false;
        int f[26]{};
        for (int i = 0; i < a.size(); ++i) {
            f[a[i] - 'a']++;
            f[b[i] - 'a']--;
        }
        for (auto n : f) if (n) return false;
        return true;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for (int i = 1; i < words.size(); ++i) {
            if (anagram(words[i], words[i - 1])) {
                // decrement as i - 1 becomes i
                words.erase(words.begin() + i--); 
            }
        }
        return words;
    }
};