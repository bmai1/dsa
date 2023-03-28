class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0, b = INT_MIN;
        for (int price: prices) {
            int tmp = a;
            a = max(a, b + price);
            b = max(b, tmp - price);
        }
        return a;
    }
};
