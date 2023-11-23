class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), q = l.size();
        vector<bool> res(q, true);
        priority_queue<int> pq;

        int t, d;
        for (int i = 0; i < q; ++i) {
            for (int j = l[i]; j <= r[i]; ++j) pq.push(nums[j]);
            t = pq.top(); pq.pop();
            d = t - pq.top();
            while (!pq.empty()) {
                if (t - pq.top() != d) res[i] = false;
                t = pq.top(); pq.pop();
            }
        }
        return res;
    }
};