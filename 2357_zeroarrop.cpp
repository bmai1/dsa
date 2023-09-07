class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op = 0, m;
        while (true) {
            m = INT_MAX;
            for (auto n : nums) if (n > 0 && n < m) m = n;
            for (auto &n : nums) if (n > 0) n -= m;
            
            ++op;
        }
        return op;
    }
};