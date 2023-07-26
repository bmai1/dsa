class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end());
        int n = score.size();
        for (int i = 0; i < n; ++i) {
            if (score[i] == sorted[n - 1]) ans.push_back("Gold Medal");
            else if (n >= 2 && score[i] == sorted[n - 2]) ans.push_back("Silver Medal");
            else if (n >= 3 && score[i] == sorted[n - 3]) ans.push_back("Bronze Medal");
            else {
                for (int j = 0; j < n; ++j) 
                    if (score[i] == sorted[j]) ans.push_back(to_string(n - j));
            } 
        }
        return ans; 
    }
};