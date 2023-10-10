class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); // no need for set
        // window template literally wtf
        for (int m = nums.size(); j < m; ++j) {
            if (nums[i] + n <= nums[j]) ++i;
        }
        return n - j + i;
    }
};