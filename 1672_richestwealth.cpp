class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int max_sum = accumulate(a[0].begin(), a[0].end(), 0);
        for (int i = 0; i < a.size(); ++i) {
            int max_guess = accumulate(a[i].begin(), a[i].end(), 0);
            if (max_guess > max_sum) {
                max_sum = max_guess;
            }
        }
        return max_sum;
    }
};
