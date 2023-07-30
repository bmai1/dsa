class Solution {
    int event(vector<vector<int>>& dp, vector<vector<int>>& events, int k, int i) {
        int n = events.size();
        if (i >= n || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        // finish current event, look for next (keep track of j)
        // j is the next available event start time.
        int j;
        for (j = i + 1; j < n; ++j) {
            if (events[j][0] > events[i][1]) break;
        }
        // compare attending this event vs. attending the next open event
        return dp[i][k] = max(event(dp, events, k, i + 1), events[i][2] + event(dp, events, k - 1, j));
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, -1));
        // recursion
        return event(dp, events, k, 0);
    }
};
