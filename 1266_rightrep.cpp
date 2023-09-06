class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), mval = -1;
        vector<int> ans(n, -1);

        // for (int i = 0; i < arr.size() - 1; ++i) {
        //     int j = i + 1;
        //     while (j < n) ans[i] = max(ans[i], arr[j++]);
        // }

        for (int i = n - 1; i >= 0; --i) {
            ans[i] = mval;
            mval = max(mval, arr[i]);
        }
        return ans;
    }
};