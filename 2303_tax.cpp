class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int income) {
        double res = 0, prev = 0;
        for (int i = 0; i < b.size(); prev = b[i++][0])
            res += max(0.0, (-prev + min(income, b[i][0])) * b[i][1] / 100);
        return res;

        double ans = 0;
        int i = 0, upper;
        for (; i < b.size(); ++i) {
            if (i == 0) upper = min(income, b[0][0]);
            else upper = min(income, b[i][0] - b[i - 1][0]);
            income -= upper;
            ans += upper * b[i][1] / 100.0;     
        }
        return ans;
    }
};