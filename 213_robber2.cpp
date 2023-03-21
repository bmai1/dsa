class Solution {
private: 
    int r(vector<int>& nums) {
        int p1 = 0, p2 = 0, tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tmp = max(p2 + nums[i], p1);
            p2 = p1;
            p1 = tmp;
        }
        return tmp;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) { return nums[0]; }
        vector<int> front(nums.begin(), nums.end() - 1);
        vector<int> back(nums.begin() + 1, nums.end());
        return max(r(front), r(back));
    }
};
