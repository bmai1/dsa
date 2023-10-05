class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = floor(nums.size() / 3.0);
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        for (auto it : freq) {
            if (it.second > n) ans.push_back(it.first);
        }
        return ans;
    }
};

// https://www.geeksforgeeks.org/n3-repeated-number-array-o1-space/#