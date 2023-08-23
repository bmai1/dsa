class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = size(set<int>(begin(nums), begin(nums) + i + 1)) - size(set<int>(begin(nums) + i + 1, end(nums)));
        }
        return diff;
    }
};