class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return ans;
        vector<int> steps {n, m - 1};

        int dir = 0;
        int row = 0, col = -1;
        
        while (steps[dir % 2]) {
            for (int i = 0; i < steps[dir % 2]; ++i) {
                row += dirs[dir][0];
                col += dirs[dir][1];
                ans.push_back(matrix[row][col]);
            }
            steps[dir % 2]--;
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};
