class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) ans = max(++curr, ans);
            else curr = 0;
        }
        return ans;
    }
};