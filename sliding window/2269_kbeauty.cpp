class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int i = 0, beauty = 0, n = s.size();
        while (i + k <= n) {
            int window = stoi(s.substr(i++, k));
            if (window && num % window == 0) ++beauty;
        }
        return beauty;
    }
};