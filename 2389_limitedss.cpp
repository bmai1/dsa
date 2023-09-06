class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
        
        for (auto q : queries) {
            int lo = 0, hi = nums.size() - 1, size = nums.size();
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] > q) {
                    size = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            ans.push_back(size);
        }
        return ans;
    }
};