class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++; 
            if (count[nums[i]] > 2) {
                nums.erase(nums.begin() + i);
                i--;
            } 
        }
        return nums.size();
    }
};
