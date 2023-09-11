class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> f;
        for (int n : nums) ++f[n];
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return f[a] == f[b] ? a > b : f[a] < f[b];
        });
        return nums;

        vector<int> ans;
        unordered_map<int, int> f;
        map<int, vector<int>> ff;
        for (int n : nums) f[n]++; // count freq of nums
        for (auto [n, cnt] : f)    // separate by freq
            for (int i = 0; i < cnt; ++i) 
                ff[cnt].push_back(n);
                     
        // sort by decreasing for same freq
        for (auto &it : ff) sort(rbegin(it.second), rend(it.second));
        for (auto [_, freq] : ff) 
            for (int n : freq)
                ans.push_back(n);

        return ans;
    }
};