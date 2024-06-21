class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // find max (customers unsatisfied) window (minutes) 
        int cnt = 0;
        for (int i = 0; i < minutes; ++i) cnt += grumpy[i] * customers[i];
        
        // if the special technique is used at t = 0:
        int max_unhappy = cnt, end = minutes - 1, n = customers.size();
       
        for (int i = minutes; i < n; ++i) {
            cnt = cnt - (grumpy[i - minutes] * customers[i - minutes]) + (grumpy[i] * customers[i]);
            if (cnt > max_unhappy) {
                max_unhappy = cnt;
                end = i;
            }
        }

        int res = 0;
        for (int i = end - minutes + 1; i <= end; ++i) grumpy[i] = 0;
        for (int i = 0; i < n; ++i) {
            if (!grumpy[i]) res += customers[i];
        }
        return res;
    }
};