class Solution {
public:
    string maximumTime(string time) {
        string res;
        if (time[0] == '?') {
            if (time[1] == '?') res += "23";
            else if (time[1] < '4')  { res += '2'; res += time[1]; }
            else { res += '1'; res += time[1]; }
        }
        else if (time[1] == '?') {
            res += time[0];
            res += (time[0] == '0' || time[0] == '1') ? '9' : '3'; 
        }
        else { res += time[0]; res += time[1]; }
        res += ":";
        res += time[3] == '?' ? '5' : time[3];
        res += time[4] == '?' ? '9' : time[4];
        return res;
    }
};