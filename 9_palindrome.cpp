class Solution {
public:
    bool isPalindrome(int x) {
        // string s = to_string(x);
        // int n = s.size();
        // for (int i = 0; i < n / 2; ++i) {
        //     if (s[i] != s[n - i - 1]) return false;
        // }
        // return true;

        if (x < 0) return false;
        vector<int> r;
        while (x > 0) {
            r.push_back(x % 10);
            x /= 10;
        }
        int n = r.size();
        for (int i = 0; i < n / 2; ++i) {
            if (r[i] != r[n - i - 1]) return false;
        }
        return true;
    }
};