class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int i = 0; i <= 1000; ++i) {
            int cnt = 0;
            for (int n : nums) {
                cnt += n >= i;
            }
            if (cnt == i) return i;
        }
        return -1;
    }
};