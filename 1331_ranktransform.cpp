class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        int n = arr.size();
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.push_back({i, arr[i]});
        }
        sort(tmp.begin(), tmp.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<int> ans(n);
        int rank = 1;
        ans[tmp[0].first] = rank;
        for (auto i = 1; i < n; ++i) {
            if (tmp[i].second != tmp[i - 1].second) ++rank;
            ans[tmp[i].first] = rank;
        }
        return ans;
    }
};