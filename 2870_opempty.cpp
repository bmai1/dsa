class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) ++m[n];
        int res = 0;
        for (auto it : m) {
            // 3 (r == 0): 3 = curr / 3 ops
            // 4 (r == 1): 2, 2 = (curr / 3) + 1 ops
            // 5 (r == 2): 3, 2 = (curr / 3) + 1 ops
            if (it.second == 1) return -1;
            res += it.second / 3 + (it.second % 3 != 0);
        }
        return res;
    }
};