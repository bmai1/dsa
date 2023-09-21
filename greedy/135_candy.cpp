class Solution {
public:
    int candy(vector<int>& r) {
        int ans = 0, n = r.size();
        if (n == 1) { return 1; }
        vector <int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; ++i) {
            if (r[i] > r[i - 1]) { left[i] = left[i - 1] + 1; }
        } 
        for (int j = n - 2; j >= 0; --j) {
            if (r[j] > r[j + 1]) { right[j] = right[j + 1] + 1; }
        }
        for (int k = 0; k < n; ++k) {
             ans += max(left[k], right[k]);
        }
        return ans;
    }
};
