class Solution {
public:
    int getLucky(string s, int k) {
        string n;
        for (char c : s) {
            n += to_string(c - 'a' + 1);
        }
        // cout << n;
        int sum;
        for (int i = 0; i < k; ++i) {
            sum = 0;
            for (char c : n) {
                sum += (c - '0');
            }
            n = to_string(sum);
        }
        return sum;
    }
};