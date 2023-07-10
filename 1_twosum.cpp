class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // First Solution:
        // for (int i = 0; i < nums.size(); ++i) {
        //     for (int j = 0; j < nums.size(); ++j) {
        //         if (nums[i] + nums[j] == target && i != j) {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};
        
        // Faster method one pass using hashmap (dict)
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                return { m[target - nums[i]], i };
            }
            m[nums[i]] = i;
        }
        return {};

    }
};
