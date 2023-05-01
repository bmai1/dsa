class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int score = 0;
        int m = *max_element(nums.begin(), nums.end());
        while (k--) { score += m++; }
        return score;
    }
};
