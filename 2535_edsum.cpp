class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        // element sum is the sum of all the elements in nums
        // digit sum is the sum of all the digits (not necessarily distinct) that appear in nums
        int esum = 0, dsum = 0;
        for (int n: nums) { 
            // add num
            esum += n; 
            // add digits
            while (n != 0) {
                dsum += n % 10;
                n /= 10;
            }
        }
        return abs(esum - dsum);
    }
};
