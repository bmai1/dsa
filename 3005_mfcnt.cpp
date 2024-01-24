class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mx = 0, cnt = 0;
        int f[101] = {};
        for (int n : nums) {
            if (++f[n] > mx) {
                mx = f[n];
                cnt = 1;
            }
            else if (f[n] == mx) ++cnt;
        }
        return cnt * mx;
    }
};