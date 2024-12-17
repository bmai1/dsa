class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> prefix;

        int x = arr[0];
        prefix.push_back(x);
        
        for (int i = 1; i < arr.size(); ++i) {
            prefix.push_back(x ^= arr[i]);
        }

        // for (auto q : queries) {
        //     int x = arr[q[0]];
        //     for (int i = q[0] + 1; i <= q[1]; ++i) {
        //         x ^= arr[i];
        //     }
        //     res.push_back(x);
        // }
    
        // XOR from l to r = prefix[r]⊕prefix[l−1]
        for (auto q : queries) {
            if (q[0] == 0) res.push_back(prefix[q[1]]);
            else res.push_back(prefix[q[1]] ^ prefix[q[0] - 1]);
        }
        return res;
    }
};