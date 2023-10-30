class Solution {
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int> v, int i) {
        if (i >= nums.size()) return;
        v.push_back(nums[i]);
        backtrack(nums, v, i + 1);
        ans.push_back(v);
        v.pop_back();
        backtrack(nums, v, i + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        vector<int> v;
        backtrack(nums, v, 0);
        return ans;
    }
};