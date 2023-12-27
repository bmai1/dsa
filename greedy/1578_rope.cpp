class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, n = colors.size();
        for (int i = 0; i < n; ++i) {
            int mx = 0, sum = 0, j = i; 
            while (j < n && colors[i] == colors[j]) {
                sum += neededTime[j];
                mx = max(mx, neededTime[j++]);
            }
            res += j - i > 1 ? sum - mx : 0;
            i = j - 1;
        }
        return res;
    }
};