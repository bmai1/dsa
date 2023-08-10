class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        stack<int> mstk;
        unordered_map<int, int> m;

        for (int n : n2) {
            while (!mstk.empty() && n > mstk.top()) {
                m[mstk.top()] = n;
                mstk.pop();
            }
            mstk.push(n);
        }

        vector<int> ans;
        for (int n : n1) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;

        // vector ranking with find

        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> near(n2, -1);
        stack<int> mstk;

        for (int i = 0; i < n2; ++i) {
            while (!mstk.empty() && nums2[i] > nums2[mstk.top()]) {
                near[mstk.top()] = nums2[i];
                mstk.pop();
            }
            mstk.push(i);
        }

        vector<int> ans(n1);
        for (int j = 0; j < n1; ++j) {
            int index = find(nums2.begin(), nums2.end(), nums1[j]) - nums2.begin();
            ans[j] = near[index];
        }
        return ans;
    }
};