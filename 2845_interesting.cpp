class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        int cnt = 0;
        for (int num : nums) {
            cnt += (num % mod == k);
            int mod_val = cnt % mod;
            if (mod_val == k) ++ans;   // ?
            int find = mod_val - k;    // ?
            if (find < 0) find += mod; // ? 
            ans += m[find];
            ++m[mod_val];
        }
        return ans;
    }
};