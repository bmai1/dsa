class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int,int>> v;
        for (int i = 0; i < heights.size(); ++i) v.push_back({heights[i], i});
        sort(v.rbegin(), v.rend(), [](pair<int,int> &a, pair<int,int> &b) {
            return a.first < b.first;
        });
        for (auto p : v) ans.push_back(names[p.second]);
        return ans;
    }
};