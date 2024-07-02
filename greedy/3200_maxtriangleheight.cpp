class Solution {
private:
    int ball(int red, int blue) {
        int r = 1, h = 0;
        while (red > 0 || blue > 0) {
            red -= r; 
            if (red >= 0) { ++h, ++r; }
            else break;

            blue -= r;
            if (blue >= 0) { ++h, ++r; }
            else break;
        }
        return h;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(ball(red, blue), ball(blue, red));
    }
};