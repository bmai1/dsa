class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // int c = 0;
        // for (auto v: grid) {
        //     for (int i: v) {
        //         if (i < 0) { ++c; }
        //     }
        // }
        // return c; 
        
        int ans = 0; 
        for (int i = 0; i < grid.size(); ++i) {
            if (grid[i][0] < 0) { 
                ans += grid[0].size(); 
                continue;
            }
            if (grid[i][grid[0].size() - 1] > 0) { continue; }
            int lo = 0, hi = grid[0].size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (grid[i][mid] < 0) { hi = mid - 1; }
                else { lo = mid + 1; }
            }
            ans += grid[0].size() - lo; 
            hi = lo;
        }
        return ans; 
    }
};
