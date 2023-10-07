class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int m = 0, ans = 0, n = nums.size();
        unordered_map<int, int> f;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == key) f[nums[i + 1]]++;
        }
        for (auto it : f) {
            if (it.second > m) { 
                m   = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};