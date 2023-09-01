class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int pairs = 0, rem = 0;
        unordered_map<int, int> m;
        for (int n : nums) ++m[n];
        for (auto it : m) {
            pairs += it.second / 2;
            rem += it.second % 2;
        }
        return {pairs, rem};
    }
};