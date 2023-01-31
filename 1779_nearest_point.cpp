class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min = INT_MAX, ans = -1; 
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] != x && points[i][1] != y) { continue; }
            int d = abs(x - points[i][0]) + abs(y - points[i][1]);
            if (d == 0) { return i; }
            else if (d < min) { 
                min = d; 
                ans = i; 
            }
        }
        return ans; 
    }
};
