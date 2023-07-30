class Solution {
private:
    vector<vector<int>> kSum(vector<int>& nums, int start, int k, long long t) {
        vector<vector<int>> ans;
        if (start == nums.size()) return ans;
        long long avg = t / k; // remaining k values
        if (nums[start] > avg || avg > nums.back()) return ans;
        if (k == 2) return twoSum(nums, start, t);
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (vector<int>& v : kSum(nums, i + 1, k - 1, t - nums[i])) {
                    ans.push_back({nums[i]});
                    ans.back().insert(end(ans.back()), v.begin(), v.end());
                }
            }
        }
        return ans;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int start, int t) {
        vector<vector<int>> ans; 
        int lo = start, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < t || (lo > start && nums[lo] == nums[lo - 1])) ++lo;
            else if (sum > t || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) --hi;
            else ans.push_back({ nums[lo++], nums[hi--] });
        }
        return ans;
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        return kSum(nums, 0, 4, t);
    }
};