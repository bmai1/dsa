class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (int n : nums) {
            int sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            res = min(res, sum);
        }
        return res;
    }
};
