class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n: nums) {
            m[n]++;
            if (m[n] == 2) { return n; }
        }
        return -1;
    }
};
