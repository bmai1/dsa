class Solution {
private: 
    bool isin(int end, vector<int>& i) {
        return end >= i[0] && end <= i[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // count overlapping intervals 
        int n = points.size();
        if (n == 1) return 1;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        // for (auto v : points) {
        //     for (auto c : v) cout << c << ' ';
        //     cout << endl;
        // }
        // cout << endl;

        int cnt = 0, end = points[0][1];
        for (int i = 0; i < n - 1; ++i) {
            end = min(points[i][1], points[i + 1][1]);
            // cout << "end: " << end << endl;
            while (i < n - 1 && isin(end, points[i + 1])) {
                // cout << points[i][0] << ' ' << points[i][1] << endl;
                // cout << points[i + 1][0] << ' ' << points[i + 1][1] << endl;
                ++i;
            }
            ++cnt;
        }
        return isin(end, points[n - 1]) ? cnt : cnt + 1;
    }
};