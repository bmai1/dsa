class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; 
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums[0] > 0) return {};

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            // skip repeats
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int sum = 0;
            int low = i + 1, high = nums.size() - 1;
            while (low < high) {
                sum = nums[i] + nums[low] + nums[high];
                // sum too large = lower the high value
                if (sum > 0) {
                    --high;
                }
                else if (sum < 0) ++low;
                // when sum == 0
                else {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    // avoid triplet duplicates
                    int last_low = nums[low], last_high = nums[high];  
                    // Update the low and high with last occurences of low and high
                    while (low < high && nums[low] == last_low) ++low;
                    while (low < high && nums[high] == last_high) --high;
                }
            }
        }
        return ans;

        // // too slow; (sort = O(nlogn), 3 loops = n^3, find()
        // for (int i = 0; i < nums.size()-2; ++i) {
        //     if (nums[i] > 0) break;
        //     for (int j = i + 1; j < nums.size()-1; ++j) {
        //         for (int k = i + 2; k < nums.size(); ++k) {
        //             if (i != j && i != k && j != k  && (nums[i] + nums[j] + nums[k]) == 0) {
        //                 if (nums[i] <= nums[j] && nums[j] <= nums[k]) {

        // naive to use stl to find duplicates, just skip over
        //                     vector<int> v = {nums[i], nums[j], nums[k]};
        //                     if (find(ans.begin(), ans.end(), v) == ans.end()) {
        //                         ans.push_back(v); 
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
    }
};
