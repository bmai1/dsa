class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n : nums) ++m[n];
        for (auto it : m) if (it.second % 2) return false;
        return true;
    }
};