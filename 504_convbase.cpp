class Solution {
public:
    string convertToBase7(int num) {
        // if (num == 0) return "0";
        // string ans; 
        // bool n = false;
        // if (num < 0) {
        //     n = true;
        //     num = -num;
        // }
        // while (num) {
        //     ans += to_string(num % 7);
        //     num /= 7;
        // }
        // if (n) ans += '-';
        // reverse(ans.begin(), ans.end());
        // return ans;

        int n = abs(num);
        string ans;
        do ans = to_string(n % 7) + ans;
        while (n /= 7);
        return (num >= 0 ? "" : "-") + ans;
    }
};