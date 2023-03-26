class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int maxP = 0, minP = INT_MIN;
        for (auto n : prices) {
            int tmp = maxP;
            maxP = max(maxP, minP + n);
            minP = max(minP, tmp - n - fee);
        }
        return maxP;
    }
};
