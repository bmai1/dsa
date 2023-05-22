class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        // simulating stack with vector allows more flexibility
        vector<int> stk;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] > 0 || stk.empty() || stk.back() < 0) {
                stk.push_back(a[i]);
            }
            else if (stk.back() <= -a[i]) {
                if (stk.back() < -a[i]) i--;
                stk.pop_back();
            }
        }
        return stk;
    }
};
