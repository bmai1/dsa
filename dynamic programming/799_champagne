class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[100][100] = {};
        dp[0][0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j) dp[i][j] += max((dp[i - 1][j - 1] - 1) / 2.0, 0.0); // left overflow
                dp[i][j] += max((dp[i - 1][j] - 1) / 2.0, 0.0); // right overflow
            }
        }

        // double dp[100][101] = {}; 
        // dp[0][1] = poured; // 1-index glasses to check left overflow for leftmost glass
        // for (int i = 1; i <= query_row; ++i) {
        //     for (int j = 1; j < i + 2; ++j) {
        //         dp[i][j] += max((dp[i - 1][j - 1] - 1) / 2.0, 0.0) + max((dp[i - 1][j] - 1) / 2.0, 0.0);
        //     }
        // }

        // for (int i = 0; i < 100; ++i) {
        //     for (int j = 0; j < 100; ++j) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        return min(1.0, dp[query_row][query_glass]);
    }
};