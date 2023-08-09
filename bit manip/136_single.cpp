class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto n : nums) {
            cout << bitset<8>(n) << endl;
            cout << bitset<8>(ans) << endl;
            ans ^= n;
            cout << bitset<8>(ans) << endl;
            cout << endl;
        }
        return ans;
    }
};