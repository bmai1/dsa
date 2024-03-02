class Solution {
public:
    vector<int> sortedSquares(vector<int>& n) {
        vector<int> res(n.size());
        int l = 0, r = n.size() - 1;
        int i = r;
        while (l <= r) {
            int left = n[l] * n[l];
            int right = n[r] * n[r];
            if (left > right) {
                res[i--] = left;
                ++l;
            }
            else {
                res[i--] = right;
                --r;
            }
        }
        return res;

        // vector<int> res;
        // int i = 0;
        // // find min square index
        // while (i < n.size() - 1 && n[i] * n[i] >= n[i + 1] * n[i + 1]) ++i;
        // res.push_back(n[i] * n[i]);

        // int l = i - 1, r = i + 1;

        // while (res.size() != n.size()) {
        //     while (l >= 0 && (r >= n.size() || n[l] * n[l] <= n[r] * n[r])) {
        //         res.push_back(n[l] * n[l]);
        //         --l;
        //     }
        //     while (r < n.size() && (l < 0 || n[r] * n[r] <= n[l] * n[l])) {
        //         res.push_back(n[r] * n[r]);
        //         ++r;
        //     }
        // }

        // return res;
    }
};