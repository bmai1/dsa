class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> mapped;
        for (int i = 0; i < n; ++i) {
            int tmp = nums[i];
            int val = tmp ? 0 : mapping[0];
            int m = 1;
            while (tmp) {
                val = mapping[tmp % 10] * m + val;
                m *= 10, tmp /= 10;
            }
            // using index as second value rather than nums[i] stablizes the sort!
            mapped.push_back({val, i});
        }

        // leaves equal values in same position
        // stable_sort(mapped.begin(), mapped.end());

        sort(mapped.begin(), mapped.end());

        vector<int> res;
        for (auto& p : mapped) {
            res.push_back(nums[p.second]);
        }
        return res;
    }
};