class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxKey = 0;
        unordered_map<int, vector<int>> m;
        for (int r = nums.size() - 1; r >= 0; --r) {
            for (int c = 0; c < nums[r].size(); ++c) {
                m[r + c].push_back(nums[r][c]);
                maxKey = max(maxKey, r + c);
            }
        }
        vector<int> ans;
        for (int key = 0; key <= maxKey; ++key) {
            for (int v : m[key]) ans.push_back(v);
        }
        return ans;

        // int m = nums.size(), n = 0, row, col;
        // for (auto& r : nums) n = max(n, (int) r.size());
        // // for (auto& r : nums) while (r.size() < n) r.push_back(0); // mark empty
        // vector<int> ans;
        // for (int i = 0; i < m; ++i) {
        //     row = i, col = 0;
        //     while (row >= 0 && col < n) {
        //         if (col >= nums[row].size()) {
        //             row--;
        //             col++;
        //         }
        //         else ans.push_back(nums[row--][col++]);
        //     }
        // }
        // for (int i = 1; i < n; ++i) {
        //     row = m - 1, col = i;
        //     while (row >= 0 && col < n) {
        //         if (col >= nums[row].size()) {
        //             row--;
        //             col++;
        //         }
        //         else ans.push_back(nums[row--][col++]);
        //     }
        // }
        // return ans;
    }
};