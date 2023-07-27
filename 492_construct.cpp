class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> d(2);
        int m = INT_MAX;
        for (int i = 1; i <= sqrt(area); ++i) {
            if (area % i == 0) {
                if (area / i == i) return { i, i }; // square root
                else if (abs(i - (area / i)) < m) { // minimize difference between two factors
                    m = abs(i - (area / i));
                    d[0] = area / i, d[1] = i; 
                }
            }
        }
        return d;
    }
};