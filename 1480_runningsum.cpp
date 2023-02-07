class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // for (int i = 1; i < nums.size(); ++i) {
        //     nums[i] += nums[i - 1];
        // }
        // return nums;
        int sum = 0; 
        vector<int> ans; 
        for (auto n: nums) {
            ans.push_back(sum += n);
        }
        return ans; 
    }
};
