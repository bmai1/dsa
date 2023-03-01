class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<pair<int,int>> hold;
        for (int i = 0; i < mat.size(); ++i) {
            int count = 0;
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 1) {
                    ++count;
                }
            }
            hold.push_back(make_pair(count, i));
        }
        sort(hold.begin(), hold.end());
        for(int i = 0; i < k; ++i) {
            ans.push_back(hold[i].second);
        }
        return ans;
    }
};
