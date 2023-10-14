// https://www.youtube.com/watch?v=qMZJunF5UaI

class Solution {
    int rec(int i, int remain, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        if (remain <= 0) return 0;
        if (i == cost.size()) return 1e9; // didn't paint all walls 
        if (dp[i][remain] != -1) return dp[i][remain];
        
        int paint = cost[i] + rec(i + 1, remain - 1 - time[i], cost, time, dp);
        int skip = rec(i + 1, remain, cost, time, dp); // delegate to free painter 
        dp[i][remain] = min(paint, skip);
        return dp[i][remain];
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(0, n, cost, time, dp);
    }
};