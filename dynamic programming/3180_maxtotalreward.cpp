class Solution {
private:
    int dp[2001][4000];
    int re(vector<int>& r, int curr) {
        int res = curr;
        for (int i = 0; i < r.size(); ++i) {
            if (dp[i][curr]) return dp[i][curr];
            if (r[i] > curr) {
                int tmp = r[i];
                r[i] = -1;
                res = max(res, re(r, curr + tmp));
                dp[i][curr] = res;
                r[i] = tmp;
            }
            else break; // works due to sort
        }
        return res;
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.rbegin(), rewardValues.rend());
        return re(rewardValues, 0);
    }
};