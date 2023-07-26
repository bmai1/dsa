class Solution {
public:
    int findPoisonedDuration(vector<int>& tS, int d) {
        int ans = 0, n = tS.size();
        for (int i = 0; i < n - 1; ++i) 
            ans += (tS[i] + d) < tS[i + 1] ? d : tS[i + 1] - tS[i];
        return ans + d;
    }
};