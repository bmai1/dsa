class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) { return s; }
        // create empty 2d char array
        string arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = "";
        }

        // form zig zag by shifting index when at top and bottom
        string shift = "down";
        int index = 0;
        for (int j = 0; j < s.length(); ++j) {
            arr[index] += s[j];
            if (index == 0) { shift = "down"; }
            if (index == n - 1) { shift = "up"; }
            shift == "down" ? ++index : --index;
        }

        // concatenate strings
        string ans;
        for (int k = 0; k < n; ++k) {
            ans += arr[k];
        }
        return ans;
    }
};
