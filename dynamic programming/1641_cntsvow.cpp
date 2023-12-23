class Solution {
    // int pyramidSum(int base) {
    //     int res = 0;
    //     for (int i = base; base >= 0; --i) {
    //         for (int j = 1; j <= i; ++j) {
    //             res += j;
    //         }
    //     }
    //     return res;
    // }
public:
    int countVowelStrings(int n) {
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;

        vector<vector<int>> dp(n + 1, vector<int>(6));  // 2d dp to store previous values of each char
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= 5; ++k) {
                //         a
                dp[i][k] = dp[i][k - 1] + (i > 1 ? dp[i - 1][k] : 1);
            }
        }
        return dp[n][5];

        // adding the summation of pyramid sums 1...n?

        // eee, eei, eeo, eeu
        // eii, eio, eiu,
        // eoo, eou,
        // eou

        // eeee, eeei, eeeo, eeeu
        // eeii, eeio, eeiu
        // eeoo, eeou,
        // eeuu,
        
        // adds f[i](n - 1)

        // eiii, eiio, eiiu
        // eioo, eiou
        // eiuu
        // eooo, eoou
        // eouu,
        // euuu

        // a = 1, 5, 15, 35 = f(n - 1)
        // e = 1, 4, 10, 20
        // i = 1, 3, 6,  10
        // o = 1, 2, 3,  4 = n
        // u = 1, 1, 1,  1 = 1
    }
};