class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    long long re(int A, int L, int total, int n) {
        if (A >= 2 || L == 3) return 0;
        if (total == n) return 1;
        if (dp[A][L][total]) return dp[A][L][total];
        return dp[A][L][total] = (re(A + 1, 0, total + 1, n) % mod + re(A, L + 1, total + 1, n) % mod + re(A, 0, total + 1, n) % mod) % mod;
    }
public:
    int checkRecord(int n) {
        dp.resize(2, vector<vector<int>>(3, vector<int>(n)));
        return re(0, 0, 0, n);
        
        // vector<int> dp(n + 1);
        // dp[0] = 3;
        // for (int i = 1; i <= n; ++i) {
        //     dp[i] = 
        // }
        // return dp[n];
    }
};