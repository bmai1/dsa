class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; ++i) freq[nums[i]]++;
        for (int i = k; i < nums.size() + 1; ++i) {
            int sum = 0;
            priority_queue<pair<int, int>> pq;
            for (auto it : freq) {
                pq.push({it.second, it.first});
            }
            for (int j = 0; j < x; ++j) {
                if (!pq.empty()) {
                    sum += pq.top().first * pq.top().second;
                    pq.pop();
                }
            }
            res.push_back(sum);
            
            if (i < nums.size()) {
                freq[nums[i]]++;
                freq[nums[i - k]]--;
                if (!freq[nums[i - k]]) freq.erase(nums[i - k]);
            }
        }

        return res;
    }
};
