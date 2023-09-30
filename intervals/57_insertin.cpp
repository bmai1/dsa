class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& nin) {
        int n = in.size(), i = 0;
        vector<vector<int>> ans;
        while (i < n && in[i][1] < nin[0]) ans.push_back(in[i++]);
        while (i < n && nin[1] >= in[i][0]) {
            nin[0] = min(nin[0], in[i][0]);
            nin[1] = max(nin[1], in[i++][1]);
        }
        ans.push_back(nin);
        while (i < n) ans.push_back(in[i++]);
        return ans;
    }
};