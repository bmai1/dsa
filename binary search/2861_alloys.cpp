class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        // n = number of metals   (size of machine)
        // k = number of machines (size of composition)
        long long lo = 0, hi = INT_MAX;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            bool mid_alloys = false;
            for (int i = 0; i < k; ++i) {
                long long cur_cost = 0;
                for (int j = 0; j < n; ++j) {
                    if (mid * composition[i][j] > stock[j]) {
                        cur_cost += (mid * composition[i][j] - stock[j]) * cost[j];
                    }
                }
                if (cur_cost <= budget) { 
                    lo = mid + 1; 
                    mid_alloys = true;
                    break;
                }
            }
            if (!mid_alloys) hi = mid - 1;
        }
        return hi;
    }
};