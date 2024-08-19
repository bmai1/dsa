class Solution {
private:
    int dp[1001][1001];
    int re(int n, int curr, int prev) {
        if (curr > n) return n + 1;
        if (n == curr) return 0;
        if (dp[curr][prev]) return dp[curr][prev];

        int copy = 2 + re(n, curr * 2, curr);
        int paste = 1 + re(n, curr + prev, prev);

        return dp[curr][prev] = min(copy, paste);
    }
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        // always copy first
        return 1 + re(n, 1, 1);
    }
};