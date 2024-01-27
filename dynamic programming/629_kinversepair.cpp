class Solution {
private:
    int mod = 1e9 + 7;
    // int dp[1001][1001] = {};
public:
    int kInversePairs(int n, int k) {
        // if (k == 0) return 1;
        // if (k < 0) return 0;
        // if (!dp[n][k]) {
        //     dp[n][k] = 1;
        //     for (int i = 0; i < n; ++i) {
        //         dp[n][k] = (dp[n][k] + kInversePairs(n - 1, k - i)) % mod;
        //     }
        // }
        // return dp[n][k] - 1;

        int dp[1001][1001] = {1};

        // for (int N = 1; N <= n; ++N) {
        //     for (int K = 0; K <= k; ++K) {
        //         for (int i = 0; i <= min(K, N - 1); ++i) {
        //             dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % mod;
        //         }
        //     }
        // }

        for (int N = 1; N <= n; ++N) {
            for (int K = 0; K <= k; ++K) {
                // sliding window instead of iterating over k - 1
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % mod;
                if (K >= N)
                    dp[N][K] = (mod + dp[N][K] - dp[N - 1][K - N]) % mod;
            }
        }
        return dp[n][k];

    }
};