class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // TLE
        // for (int i = 0; i < nums.size(); ++i) {
        //     for (int j = i; j < nums.size(); ++j) {
        //         if (abs(i - j) > k) { break; }
        //         if (i != j && abs(i - j) <= k && nums[i] == nums[j]) { return true; }
        //     }
        // }
        // return false;

        unordered_set<int> m;
        if (k <= 0) { return false; }
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) { m.erase(nums[i - k - 1]); }
            if (m.find(nums[i]) != m.end()) { return true; }
            m.insert(nums[i]);
        }
        return false;
    }
};
