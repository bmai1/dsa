class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freq;
        for (int c : nums) freq[c]++;
        if (freq.size() <= 1) return 0;
        int ans = 0;
        for (auto it = freq.begin(); it != prev(freq.end()); ++it) {
            if (it->first + 1 == next(it)->first) {
                ans = max(ans, it->second + next(it)->second);
            }
        }
        return ans;

        // unordered_map<int, int> freq;
        // for (int c : nums) freq[c]++;
        // if (freq.size() <= 1) return 0;
        // sort(nums.begin(), nums.end());
        // int ans = 0;
        // for (int i = 0; i < nums.size() - 1; ++i) {
        //     if (nums[i + 1] - nums[i] == 1) {
        //         ans = max(ans, freq[nums[i + 1]] + freq[nums[i]]);
        //     }
        // }
        // return ans;
    }
};