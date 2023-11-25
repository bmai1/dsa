class Solution {
public:
    int countTime(string time) {
        int res = 1;
        if (time[4] == '?') res *= 10;
        if (time[3] == '?') res *= 6;
        if (time[0] == '?' && time[1] == '?') res *= 24;
        else {
            if (time[1] == '?') res *= time[0] == '2' ? 4 : 10;
            if (time[0] == '?') res *= time[1] <  '4' ? 3 : 2;
        }
        return res;
    }
};