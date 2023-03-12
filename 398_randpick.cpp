class Solution {
public:
    vector<int> _nums;
    Solution(vector<int>& nums) {
        _nums = nums;  
    }
    int pick(int target) {
        vector<int> p;
        for (int i = 0; i < _nums.size(); ++i) {
            if (_nums[i] == target) {
                p.push_back(i);
            }
        }
        int r = rand() % p.size();
        return p[r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
