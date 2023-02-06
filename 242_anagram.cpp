class Solution {
public:
    bool isAnagram(string s, string t) {
        // cringe solution
        if (s.length() != t.length()) return false;
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;

        // array implementation, fill with 0s
        int arr[26] = {0};
        int n = s.length();
        // trying to get all equal ascii values in array 
        for (int i = 0; i < n; ++i) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (arr[i]) return false;
        }
        return true;
    }
};
