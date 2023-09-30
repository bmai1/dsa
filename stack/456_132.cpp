class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int m = nums[0];
        vector<int> mins = {m};
        for (auto n : nums) {
            m = min(m, n);
            mins.push_back(m);
        }
        stack<int> stk;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] <= mins[i]) continue;
            while (!stk.empty() && stk.top() <= mins[i]) stk.pop();
            if (!stk.empty() && stk.top() < nums[i]) return true;
            stk.push(nums[i]);   
        }
        return false;
    }
};