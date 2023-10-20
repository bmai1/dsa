class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0; 
        int j = 0; 
        while (j < nums.size() && nums[j] == 0) ++j;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) ++cnt;
            else if (i != j) {
                if (cnt < k) { 
                    return false;
                }
                cnt = 0;
            }
        }
        return true;
    }
};