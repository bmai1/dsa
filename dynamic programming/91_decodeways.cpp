// class Solution {
// private:
//     int dp[100];
//     int r(string s, int i) {
//         if (i > s.size()) return 0;
//         if (i == s.size()) return 1;
//         if (dp[i]) return dp[i];
//         int ways = 0;
//         char c = s[i];
//         if (c != '0') ways += r(s, i + 1);
//         if (i < s.size()) {
//             string alt = string(1, s[i]) + s[i + 1];
//             if (alt >= "10" && alt <= "26") {
//                 ways += r(s, i + 2);
//             }
//         }
//         dp[i] = ways;
//         return ways;
//     }
// public:
//     int numDecodings(string s) {
//         return r(s, 0);
//     }
// };

class Solution {
private:
    vector<int> dp;
    int r(string& s, int i) {
        if (dp[i] > -1) return dp[i];
        if (s[i] == '0') return dp[i] = 0;
        // decode single digit
        int ways = r(s, i + 1);
        // try to decode two digits
        if (i < s.size() - 1) {
            string alt = s.substr(i, 2);
            if (alt >= "10" && alt <= "26") {
                ways += r(s, i + 2);
            }
        }
        return dp[i] = ways;
    }
public:
    int numDecodings(string s) {
        dp.resize(s.size() + 1, -1);
        dp[s.size()] = 1;
        return r(s, 0);
    }
};