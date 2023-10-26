class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // O(N) to create hashset
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0, cnt;
        for (auto n : s) {
            // s.count() is only O(1)!
            if (!s.count(n - 1)) {
                cnt = 1;
                while (s.count(n + cnt)) ++cnt;
                res = max(res, cnt);
            }
        }
        return res;
    }
};