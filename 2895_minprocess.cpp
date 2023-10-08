class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.rbegin(), t.rend());
        int ans = 0, i = 0, n = t.size();
        for (int j = 0; j < n;) {
            for (int k = 0; k < 4 && j < n; ++k) {
                ans = max(ans, p[i] + t[j++]);
            }
            ++i;
        }
        return ans;
    }
};