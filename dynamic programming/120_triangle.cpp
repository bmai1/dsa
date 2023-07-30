class Solution {
private: 
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // find min path sum
        if (triangle.size() == 0) { return 0; }
        if (triangle.size() == 1) { return triangle[0][0]; }

        // creates copy of last row in triangle
        vector<int> minlen(triangle.back());

        for (int row = triangle.size() - 2; row >= 0; --row) {
            for (int i = 0; i <= row; ++i) {
                minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[row][i];
            }
        }
        return minlen[0];
        // "real" - sophia
    }
};
