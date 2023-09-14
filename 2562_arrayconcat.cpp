class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            string cat;
            cat += to_string(nums[i]) + to_string(nums[n - i - 1]);
            res += stoll(cat);
        }
        return n % 2 ? res + nums[n / 2] : res;
    }
};