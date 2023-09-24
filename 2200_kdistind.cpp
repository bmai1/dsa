class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        // vector<int> keys;
        // int n = nums.size();
        // for (int i = 0; i < n; ++i) 
        //     if (nums[i] == key) 
        //         keys.push_back(i);
        // for (int i = 0; i < n; ++i) {
        //     for (auto j : keys) {
        //         if (abs(i - j) <= k) {
        //             ans.push_back(i);
        //             break;
        //         }
        //     }
        // }

        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                for (j = max(j, i - k); j <= i + k && j < nums.size(); ++j) {
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};