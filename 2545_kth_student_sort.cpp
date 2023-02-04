class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        vector<int> hold;
        for (auto v : score) {
            hold.push_back(v[k]);
        }
        // sort k scores in decreasing order
        sort(hold.begin(), hold.end(), greater<int>());

        // find k score
        int index = 0; 
        for (int i = 0; i < score.size(); ++i) {
            // sort finished
            if (ans.size() == score.size()) { break; }
            if (score[i][k] == hold[index]) {
                ans.push_back(score[i]);
                index++;
                // reset loop to look for next k score
                i = -1;
            }
        }
        return ans;
    }
};
