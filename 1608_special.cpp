class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int i = 0; i < 1000; ++i) {
            int x = i + 1;
            int count = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (x <= nums[j]) { ++count; }
            }
            if (count == x) { return x; }
        }
        return -1; 
    }
};
