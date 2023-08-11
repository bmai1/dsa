class Solution {
private:
    unordered_map<string, int> dp;
    string tail(string& word) {
        return word.substr(1);
    }
public:
    int minDistance(string w1, string w2) {
        // string key = w1 + "#" + w2; 
        // if (dp.count(key)) return dp[key];
        // if (w1.size() == 0) return w2.size();
        // if (w2.size() == 0) return w1.size();
        // if (w1[0] == w2[0]) return minDistance(tail(w1), tail(w2));

        // int a = minDistance(tail(w1), w2);
        // int b = minDistance(w1, tail(w2));
        // int c = minDistance(tail(w1), tail(w2));

        // int res = 1 + min(a, min(b, c));
        // dp[key] = res;
        // return res;

        int m = w1.size(), n = w2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (w1[i - 1] == w2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else {
                    int r = dp[i - 1][j - 1]; // replace
                    int a = dp[i][j - 1];     // add (insert)
                    int d = dp[i - 1][j];     // delete
                    dp[i][j] = 1 + min(r, min(a, d));
                }
            }
        }
        return dp[m][n];
    }
};