class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> stk; // <index, price>
        vector<int> res = prices;

        for (int j = 0; j < prices.size(); ++j) {
            int p = prices[j];
            while (!stk.empty() && stk.top().second >= p) {
                int i = stk.top().first; 
                res[i] -= p;
                stk.pop();
            }
            stk.push({j, p});
        }

        return res;
    }
};
