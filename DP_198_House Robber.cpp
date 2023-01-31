class Solution {
public:
    int rob(vector<int>& nums) {
        // find max sum of elements without robbing adjacent houses
        // should not be every other house, the robbing house has to be higher than sum of two adjacent sides
        
        // base case
        if (nums.size() == 0) { return 0; }
        int prev1 = 0, prev2 = 0;
        for (int num : nums) {
            int t = prev1; 
            prev1 = max(prev2 + num, prev1);
            prev2 = t;
        }
        return prev1;
    }
};
