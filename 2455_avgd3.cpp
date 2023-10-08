class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) 
            if (!(nums[i] % 2) && !(nums[i] % 3)) 
                ++cnt, sum += nums[i];
        return cnt ? sum / cnt : 0;
    }
};