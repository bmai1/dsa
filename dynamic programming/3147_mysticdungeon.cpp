class Solution {
private:
    vector<int> dp;
    int re(vector<int>& energy, int n, int k) {
        if (n < 0) return 0;
        if (dp[n] != INT_MAX) return dp[n];
        return dp[n] = max(energy[n], energy[n] + re(energy, n - k, k));
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // int mx = INT_MIN;
        // for (int i = 0; i < energy.size(); ++i) { 
        //     int curr = 0;
        //     for (int j = i; j < energy.size(); j += k) {
        //         curr += energy[j];
        //     }
        //     mx = max(mx, curr);
        // }
        // return mx;
        
        int n = energy.size();
        int mx = INT_MIN;
        dp.resize(n, INT_MAX);
        
        for (int i = n - 1; i >= n - k; --i) {
            mx = max(mx, re(energy, i, k));
        }
        
        return mx;
        
        // int mx = INT_MIN;
        // int n = energy.size();
        // vector<int> dp(n);
        // for (int i = 0; i < k; ++i) {
        //     dp[i] = energy[i];
        // }
        // for (int i = k; i < n; ++i) {
        //     dp[i] = max(energy[i] + dp[i - k], energy[i]);
        //     mx = max(mx, dp[i]);
        // }
        // return mx;
    }
};