class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mx, mn;
        int i = 0, j = 0;
        for (; j < nums.size(); ++j) {
            while (!mx.empty() && mx.back() < nums[j]) mx.pop_back();
            while (!mn.empty() && mn.back() > nums[j]) mn.pop_back();
            mx.push_back(nums[j]);
            mn.push_back(nums[j]);
            if (mx.front() - mn.front() > limit) {
                if (mx.front() == nums[i]) mx.pop_front();
                if (mn.front() == nums[i]) mn.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};