class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            int n = i;
            while (n > 0) {
                if (!(n % 10) || i % (n % 10)) break; 
                n /= 10;
            }
            if (!n) ans.push_back(i);
        }
        return ans;
    }
};