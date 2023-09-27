class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(), dir = k > 0 ? 1 : -1;
        vector<int> ans(n);
        if (!k) return ans;
        for (int i = 0; i < n; ++i) {
            for (int cnt = 0, j = i + dir; cnt < abs(k); ++cnt) {
                if (j == n) j = 0;
                else if (j == -1) j = n - 1;
                ans[i] += code[j];
                j += dir;
            }
        }
        return ans;
    }
};