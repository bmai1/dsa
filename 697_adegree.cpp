class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int mfreq = 0, ans = INT_MAX;
        unordered_map<int, int> freq;
        vector<int> deg;
        for (auto num : nums) freq[num]++;
        for (auto it : freq) {
            if (it.second > mfreq) {
                deg.clear();
                deg.push_back(it.first);
                mfreq = it.second;
            }
            else if (it.second == mfreq) deg.push_back(it.first);
        }
        if (mfreq == 1) return 1;
        for (auto d : deg) {
            int start = -1, end;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == d) {
                    if (start == -1) start = i;
                    else end = i;
                }
            } 
            ans = min(ans, end - start + 1);
        }
        return ans;
    }
};