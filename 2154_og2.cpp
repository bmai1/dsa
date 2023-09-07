class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n[1001]{};
        for (int num : nums) ++n[num];
        while (original <= 1000 && n[original]) original *= 2;
        return original;
        
        // unordered_set<int> s(nums.begin(), nums.end());
        // while (s.count(original)) original *= 2;
        // return original;

        // unordered_map<int, int> m;
        // for (int n : nums) ++m[n];
        // while (m[original]) original *= 2;
        // return original;

        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size(); ++i) 
        //     if (nums[i] == original) original *= 2; 
        // return original;
    }
};