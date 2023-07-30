class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target && i != j) {
                    return {i, j};
                }
            }
        }
        return {};
        
        // One pass using hashmap (dict)
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                return { m[target - nums[i]], i };
            }
            m[nums[i]] = i;
        }
        return {};
        
        // Store index, sort, two pointers
        vector<pair<int, int>> ind;
        for (int i = 0; i < nums.size(); ++i) {
            ind.push_back({nums[i], i});
        }
        sort(ind.begin(), ind.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.first < b.first;
        });

        int sum, lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            sum = ind[lo].first + ind[hi].first;
            if (sum > target) --hi;
            else if (sum < target) ++lo; 
            // indices are changed in sort
            else return {ind[lo].second, ind[hi].second};
        }
        return {};
    }
};
