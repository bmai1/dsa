class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<double> s;
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            s.insert((nums[i] + nums[n - i - 1]) / 2.0);
        }
        return s.size();
    }
};