class Solution {
private: 
    int ans = 0; 
    void backtrack(vector<int>& nums, vector<int>& ss, int start) {
        int ssxor = 0;
        for (int n : ss) ssxor ^= n;
        ans += ssxor;
        for (int j = start; j < nums.size(); ++j) {
            ss.push_back(nums[j]);
            backtrack(nums, ss, j + 1);
            ss.pop_back();
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ss;
        backtrack(nums, ss, 0);
        return ans;
    }
};