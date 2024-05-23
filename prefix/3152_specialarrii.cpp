class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<bool> res;
//         vector<int> v; // track violations 
//         for (int i = 0; i < nums.size() - 1; ++i) {
//             if (nums[i] % 2 == nums[i + 1] % 2) v.push_back(i);
//         }
//         for (auto q : queries) {
//             bool flag = true;
            
//             // if i && i + 1 included in interval, invalid
//             for (int i : v) {
//                 if ((q[0] <= i && q[1] >= i) && (q[0] <= i + 1 && q[1] >= i + 1)) {
//                     flag = false;
//                     break;
//                 }
//             }
//             res.push_back(flag);
//         }
//         return res;
        
        int n = nums.size();
        vector<int> v(n);
        vector<bool> res;
        for (int i = 0; i < n - 1; ++i) {
            v[i + 1] = v[i];
            if (nums[i] % 2 == nums[i + 1] % 2) {
                v[i + 1]++;
            }
        }
        
        for (auto q : queries) {
            res.push_back(v[q[1]] - v[q[0]] == 0);
        }
        return res;
    }
};