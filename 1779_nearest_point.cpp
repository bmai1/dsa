class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min = INT_MAX, ans = -1; 
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] != x && points[i][1] != y) { continue; }
            // manhattan distance between two points = abs(x2 - x1) + abs(y2 - y1)
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
