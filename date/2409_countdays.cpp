class Solution {
    int days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int dayOfYear(string &d) {
        return days[10 * (d[0] - '0') + d[1] - '0' - 1] + 10 * (d[3] - '0') + d[4] - '0';
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        return max(0, min(dayOfYear(leaveAlice), dayOfYear(leaveBob)) - max(dayOfYear(arriveAlice), dayOfYear(arriveBob)) + 1);
    }
};