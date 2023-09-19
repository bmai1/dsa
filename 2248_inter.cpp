class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<int, int> f;
        for (auto r : nums) 
            for (auto c : r)
                ++f[c];

        int n = nums.size();
        for (auto it : f) 
            if (it.second == n) ans.push_back(it.first);

        sort(ans.begin(), ans.end());
        return ans;
    }
};