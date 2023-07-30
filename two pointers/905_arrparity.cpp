class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // vector<int> ans;
        // for (int n : nums) if (!(n % 2)) ans.push_back(n);
        // for (int n : nums) if (n % 2) ans.push_back(n); 
        // return ans;

        int j = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[j]);
                ++j;
            }
        }
        return nums;
    }
};