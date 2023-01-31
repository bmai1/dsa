class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        float delta_x = c[1][0] - c[0][0];
        float delta_y = c[1][1] - c[0][1];

        // vertical line, check all same x-values
        if (delta_x == 0) { 
            for (auto v : c) {
                if (v[0] != c[0][0]) { return false; }
            }
            return true;
        }
        // horizontal line, check all same y-values
        if (delta_y == 0) { 
            for (auto v : c) {
                if (v[1] != c[0][1]) { return false; }
            }
            return true;
        }

        // slope = (y2 - y1) / (x2 - x1)
        float slope = delta_y / delta_x;
        for (int i = 0; i < c.size() - 1; ++i) { 
            if (c[i + 1][0] - c[i][0] == 0) { return false; }
            // if different slope
            if ((c[i + 1][1] - c[i][1]) / (float(c[i + 1][0] - c[i][0])) != slope) { 
                return false;
            }
        }
        return true; 
    }
};
