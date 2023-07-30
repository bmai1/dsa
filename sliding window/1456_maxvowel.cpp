class Solution {
public:
    int maxVowels(string s, int k) {
        // TLE
        // int ans = 0; 
        // for (int i = 0; i < s.size(); ++i) {
        //     int curr = 0;
        //     for (int j = i; j < i + k; ++j) {
        //         if (j > s.size() - 1) { break; }
        //         if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
        //             ++curr;
        //         }
        //     }
        //     ans = max(ans, curr);
        // }
        // return ans;
        
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0, curr = 0;
        // first window to intialize max
        for (int i = 0; i < k; ++i) {
            if (count(v.begin(), v.end(), s[i])) { ++curr; }
        }
        ans = curr;
        for (int i = k; i < s.size(); ++i) {
            if (curr == k) { return k; }
            if (count(v.begin(), v.end(), s[i])) { ++curr; }
            // subtract number of vowels when it falls out of window range
            if (i >= k && count(v.begin(), v.end(), s[i - k])) { --curr; }
            ans = max(ans, curr);
        }
        return ans;
    }
};
