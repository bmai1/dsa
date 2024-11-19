class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {    
        unordered_map<int, int> m;
        long long mx = 0, sum = 0;
        
        /*
        // count not distinct
        int n_d = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            if (++m[nums[i]] > 1) n_d++;
        }
        if (!n_d) mx = sum;

        for (int i = k; i < nums.size(); ++i) {
            sum = sum - nums[i - k] + nums[i];
            if (--m[nums[i - k]] >= 1) n_d--;
            if (++m[nums[i]] > 1) n_d++;
            if (!n_d) mx = max(mx, sum);
        }
        */

        // can just count size of map since it's distinct by default
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            m[nums[i]]++;
            
            if (i >= k - 1) {
                if (m.size() == k) mx = max(mx, sum);
                sum -= nums[i - k + 1];
                if (--m[nums[i - k + 1]] == 0) m.erase(nums[i - k + 1]);
            }
        }

        return mx;
    }
};