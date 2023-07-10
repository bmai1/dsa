class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
            if (s.size() == 3) return num;
        }
        return *max_element(nums.begin(), nums.end());
    }
};
