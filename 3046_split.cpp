class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> f(101);
        for (int n : nums) {
            if (++f[n] > 2) return false;
        }
        return true;
    }
};