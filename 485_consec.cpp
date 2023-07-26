class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, curr = 0;
        for (int n : nums) {
            if (n) ans = max(++curr, ans);
            else curr = 0;
        }
        return ans;
    }
};