class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        int n = tmp.size();
        vector<int> ans(n, 0);
        stack<int> mstk;
        for (int i = 0; i < n; ++i) {
            while (!mstk.empty() && tmp[i] > tmp[mstk.top()]) {
                // difference between current day and index of next greater element
                ans[mstk.top()] = i - mstk.top();
                mstk.pop();
            }
            mstk.push(i);
        }
        return ans;
    }
};