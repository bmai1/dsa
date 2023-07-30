class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> m, n;
        for (auto num : nums) n[num]++;
        int right = 0, left = 0, cnt = 0;
        while (right < nums.size()) {
            m[nums[right]]++;
            while (left <= right && m.size() == n.size()) {
                if (--m[nums[left]] == 0) m.erase(nums[left]);
                ++left;
                cnt += nums.size() - right;
            }
            ++right;
        }
        return cnt;
    }
};