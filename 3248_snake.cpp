class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int res = 0;
        for (string& s : commands) {
            if (s == "LEFT") --res;
            if (s == "RIGHT") ++res;
            if (s == "DOWN") res += n;
            if (s == "UP") res -= n;
        }
        return res;
    }
};