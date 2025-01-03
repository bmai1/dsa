class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> currs;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                currs.push_back(i);
            }
        }
        int res = 0;
        for (int curr : currs) {
            int left = 0, right = 0;
            for (int i = 0; i < curr; ++i) left += nums[i];
            for (int i = curr; i < nums.size(); ++i) right += nums[i];
            if (left == right) res += 2; // direction doesn't matter
            else if (abs(left - right) == 1) res++; // can only go one direction
        }
        return res;
    }
};
