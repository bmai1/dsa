class Solution {
struct hash {
    std::size_t operator()(std::vector<int> const& vec) const {
        std::hash<uint32_t> h;
        std::size_t ret = vec.size();
        for(auto& i : vec) {
            ret ^= h(i) | i;
        }
        return ret;
    }
};   
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0; 
        // hash to store vectors in map
        unordered_map<vector<int>, int, hash> m;
        for (vector<int> r : grid) { m[r]++; }
        for (int col = 0; col < grid[0].size(); ++col) {
            vector<int> tmp;
            for (int row = 0; row < grid.size(); ++row) {
                tmp.push_back(grid[row][col]);
            }
            // add number of rows that match columns
            ans += m[tmp];
        }
        return ans;
    }
//     int ans = 0; 
//           // create columns array
//           vector<vector<int>> cols;
//           for (int i = 0; i < grid[0].size(); ++i) {
//               vector<int> col;
//               for (int j = 0; j < grid.size(); ++j) {
//                   col.push_back(grid[j][i]);
//               }
//               cols.push_back(col);
//           }
//           for (int i = 0; i < cols.size(); ++i) {
//               for (int j = 0; j < grid.size(); ++j) {
//                   if (cols[i] == grid[j]) {
//                       ++ans;
//                   }
//               }
//           }
//           return ans;
};
