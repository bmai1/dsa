class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int cnt = 0, pos = 0; 
        for (int n : nums) cnt += !(pos += n); 
        return cnt;
    }
};