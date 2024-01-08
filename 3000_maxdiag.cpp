class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        double max_d = 0;
        for (auto r : dimensions) {
            double d = sqrt(r[0] * r[0] + r[1] * r[1]);
            if (d > max_d) {
                max_d = d;
                area = r[0] * r[1];
            }
            else if (d == max_d) {
                area = max(area, r[0] * r[1]);
            }
        }
        return area;
    }
};