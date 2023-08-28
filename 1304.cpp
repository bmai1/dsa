class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int i = 0, u = 1;
        if (!(n % 2)) {
            for (int i = 0; i < n; ++i) {
                if (i % 2) {
                    ans.push_back(-u);
                    ++u;
                }
                else ans.push_back(u);
            }
        }
        else {
            ans.push_back(0);
            for (int i = 1; i < n; ++i) {
                if (!(i % 2)) {
                    ans.push_back(-u);
                    ++u;
                }
                else ans.push_back(u);
                
            }
        }
        return ans;
    }
};