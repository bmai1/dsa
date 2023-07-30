class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) { return 1; }
        // when 2, return other 
        // when n==3 return m + running sum

        
        // unique path && grid[m-1][n-1]: ++ans;

        // if (m % 2 == 0 ) { return max(m, n); }
        // else {
        //     // works for 3
        //     int prev = 0;
        //     for (int i = 0; i < m; ++i) {
        //         prev += i;
        //     }
        //     return m + prev;
        // }
        
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
