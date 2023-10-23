class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for (int i = 1; i < n - 1; ++i) {
            int j = i - 1;
            while (j >= 0 && nums[j] == nums[i]) --j;
            j = max(0, j);
            int left = nums[j];

            j = i + 1;
            while (j < n && nums[j] == nums[i]) ++j;
            j = min(n - 1, j);
            int right = nums[j];

            // cout << left << ' ' << right << endl;

            if ((nums[i] > left && nums[i] > right) || (nums[i] < left && nums[i] < right)) {
                i = j - 1; // go to end of current hill or valley
                ++cnt;
            }
        }
        return cnt;
    }
};