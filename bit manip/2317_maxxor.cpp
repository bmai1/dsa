class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        for (auto n : nums) res |= n;
        return res;
    }
};