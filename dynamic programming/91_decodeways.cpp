class Solution {
private:
    int dp[100];
    int r(string s, int i) {
        if (i > s.size()) return 0;
        if (i == s.size()) return 1;
        if (dp[i]) return dp[i];
        int ways = 0;
        char c = s[i];
        if (c != '0') ways += r(s, i + 1);
        if (i < s.size()) {
            string alt = string(1, s[i]) + s[i + 1];
            if (alt >= "10" && alt <= "26") {
                ways += r(s, i + 2);
            }
        }
        dp[i] = ways;
        return ways;
    }
public:
    int numDecodings(string s) {
        return r(s, 0);
    }
};