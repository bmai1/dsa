class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obst) {
        int m = obst.size(), n = obst[0].size();
        // // base case for start and end
        // if (obst[0][0] == 1 || obst[m-1][n-1] == 1) { return 0; }

        // // check for existing path
        // // for (int i = 0; i < m; ++i) {
        // //     for (int j = 0; j < n; ++j) {
        // //         cout << obst[i][j] << ' ';
        // //     }
        // //     cout << "\n";
        // // }
        // // cout << "\n";
        // // cout << "\n";

        // vector<vector<int>> dp(m, vector<int> (n, 1));
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (obst[i][j] == 1) { dp[i][j] = 0; }
        //     }
        // }
        // for (int i = 1; i < m; ++i) {
        //     for (int j = 1; j < n; ++j) {
        //         if (obst[i][j] == 1) { dp[i][j] = 0; }
        //         else {
        //             dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //         }
        //     }
        // }
        // // for (int i = 0; i < m; ++i) {
        // //     for (int j = 0; j < n; ++j) {
        // //         cout << dp[i][j] << ' ';
        // //     }
        // //     cout << "\n";
        // // }

        // return dp[m-1][n-1];
    
        vector<int> dp(n, 0); 
        // preprocessing to simplify 
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obst[i][j]) { dp[j] = 0; }
                else if (j > 0) { dp[j] += dp[j - 1]; }
            }
        }
        return dp[n - 1];
    }
};
