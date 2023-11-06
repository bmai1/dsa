class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                s.insert(nums[j]);
                res += pow(s.size(), 2);
            }
            s.clear();
        }
        return res;
    }
};