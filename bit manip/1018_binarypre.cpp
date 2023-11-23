class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int n = 0;
        for (int i = 0; i < nums.size(); ++i) {
            n = (n * 2 + nums[i]) % 5;
            res.push_back(!n);
        }
        return res;
    }
};