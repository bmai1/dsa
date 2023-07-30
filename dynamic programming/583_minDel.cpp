class Solution {
// private: 
//     int rec(string w1, string w2, int i, int j) {
//         if (i == w1.size() && j == w2.size()) return 0;
//         if (i == w1.size()) return w2.size() - j;
//         if (j == w2.size()) return w1.size() - i;
//         if (w1[i] == w2[j]) return rec(w1, w2, i + 1, j + 1);
//         return 1 + min(rec(w1, w2, i + 1, j), rec(w1, w2, i, j + 1));
//     }

public:
    int minDistance(string word1, string word2) {
        // return rec(word1, word2, 0, 0);

        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (!i || !j) dp[i][j] = i + j;
                // match, next character
                else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // deletion
                else { dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]); }
            }   
        }
        return dp[m][n];
    }
};
