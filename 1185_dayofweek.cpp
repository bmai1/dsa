class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
        if (month < 3) {
            month += 12;
            --year;
        }
        int k = year % 100, j = year / 100;
        int dayOfWeek = (day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) - 2 * j) % 7;
        if (dayOfWeek < 0) dayOfWeek += 7;
        return days[dayOfWeek];
    }
};