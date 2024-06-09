class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // vector<int> p;
        // int sum = 0, res = 0, n = nums.size();
        // for (int i = 0; i < n; ++i) {
        //     p.push_back(sum += nums[i]);
        //     if (sum % k == 0) ++res;
        // }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < i; ++j) {
        //         if ((p[i] - p[j]) % k == 0) ++res;
        //     }
        // }
        // return res;

        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, res = 0;
        for (int n : nums) {
            int r = (sum += n) % k;
            if (r < 0) r += k; // handle negatives, keep r between [0, k - 1]
            if (m.find(r) != m.end()) res += m[r];

            // find same remainder: why?
            // because p[i] - p[j] is the subarray sum
            // p[i] % k == p[j] % k => (p[i] - p[j]) % k == 0

            m[r]++;
        }
        return res;
    }
};