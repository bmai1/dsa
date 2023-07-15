class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        // over/underflow
        return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;

        bool negative = false;
        if (x < 0) negative = true;
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        long long r = stoll(s);
        return (r > INT_MAX || r < INT_MIN) ? 0 : negative ? -r : r;
    }  
};