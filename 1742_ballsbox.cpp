class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int ans = 0;
        unordered_map<int, int> balls;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int ball = i, box = 0;
            while (ball) { box += ball % 10; ball /= 10; }
            ++balls[box];
        }
        for (auto it : balls) ans = max(ans, it.second);
        return ans;
    }
};