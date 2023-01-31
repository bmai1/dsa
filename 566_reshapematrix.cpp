class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        // invalid size
        if (r * c != mat.size() * mat[0].size()) { return mat; }
        vector<vector<int>> ans;
        vector<int> row;
        // iterate through mat rows
        for (auto r : mat) {
            for (int n : r) {
                row.push_back(n);
                // push back correct row size
                if (row.size() == c) { ans.push_back(row); row.clear(); }
            }
        }
        return ans;
    }
};
