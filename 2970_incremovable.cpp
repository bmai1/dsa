class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int prev = -1;
                bool incremovable = true;
                for (int k = 0; k < n; ++k) {
                    if (k >= i && k <= j) continue;
                    if (prev >= nums[k]) { incremovable = false; break; }
                    prev = nums[k];
                }
                res += incremovable;
            }
        }
        return res;

        // int n = nums.size();
        // int res = 0;
        // vector<int> a;
        // vector<int> s;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i; j < n; ++j) {
        //         // remove subarray nums[i..j]
        //         for (int k = 0; k < n; ++k) {
        //             if (k < i || k > j) a.push_back(nums[k]);
        //         }
        //         s = a;
        //         sort(s.begin(), s.end());
        //         res += (s == a && s.size() == set<int>(s.begin(), s.end()).size());
        //         a.clear();
        //         s.clear();
        //     }
        // }
        // return res;
    }
};