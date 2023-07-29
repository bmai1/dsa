class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> m;
        for (auto n : nums) {
            m[n]++;
            if (m[n] == 2) ans.push_back(n);   
        }
        for (int i = 1; i < nums.size() + 1; ++i) {
            if (!m[i]) { ans.push_back(i); break; }
        }
        return ans;

        // int d = 0, m = 0;
        // for (int i = 1; i <= nums.size(); ++i) {
        //     int c = 0;
        //     for (int j = 0; j < nums.size(); ++j) {
        //         if (nums[j] == i) ++c;
        //     }
        //     if (c == 2) d = i;
        //     else if (c == 0) m = i;
        //     if (d && m) break;
        // }
        // return {d, m};
    }
};