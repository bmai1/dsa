class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // int max_width = 0;
        // sort(points.begin(), points.end(),  
        //     [](const vector<int>& a, const vector<int>& b) {
        //         return a[0] < b[0];
        //     });

        set<int> x;
        for (auto &point: points) { x.insert(point[0]); }
        int ans = 0, prev = *x.begin();
        for (auto it = x.begin(); it != x.end(); ++it) {
            ans = max(ans, *it - prev);
            prev = *it;
        }
        return ans;

        // TLE

        // for (int i = 0; i < x.size(); ++i) {
        //     int width = 0;
        //     for (int j = i + 1; j < x.size(); ++j) {
        //         if (x[j] - x[i] == j - i) { width = x[j] - x[i]; }
        //     }
        //     max_width = max(max_width, width);
        // }
        // return max_width;
    
        // for (int i = 0; i < points.size(); ++i) {
        //     bool overlap = false;
        //     int start = points[i][0];
        //     for (int j = i + 1; j < points.size(); ++j) {
        //         int end = points[j][0];
        //         for (int k = i; k < j; ++k) {
        //             int curr = points[k][0];
        //             if (curr > start && curr < end) { 
        //                 overlap = true;
        //                 break; 
        //             }
        //         }
        //         if (overlap == false) {
        //             ans = max(ans, end - start);
        //         }
        //     }
        // }
        // return ans;
    }
};
