class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;  
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                if ((j | (j + 1)) == nums[i]) {
                    res.push_back(j);
                    break;
                }
            }
            if (res.size() == i) res.push_back(-1);
        }
        return res;
    }
};
