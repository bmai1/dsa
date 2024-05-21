class Solution {
private: 
    int trees(int lo, int hi) {
        if (lo >= hi) return 1;
        int cnt = 0;
        for (int i = lo; i <= hi; ++i) {
            cnt += trees(lo, i - 1) * trees(i + 1, hi);
        }
        return cnt;
    }
public:
    int numTrees(int n) {
        return trees(1, n);
        
        // int dp[20] = {};
        // dp[0] = 1;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= i; ++j) {
        //         dp[i] += dp[j - 1] * dp[i - j];
        //     }
        // }
        // return dp[n]; 
    }
};