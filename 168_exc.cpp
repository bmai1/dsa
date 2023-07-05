class Solution {
public:
    string convertToTitle(int col) {
        string ans;
        while (col > 26) {
            if (col % 26 == 0) { 
                ans += 'Z'; 
                --col; 
            }
            else {
                ans += char ((col % 26) + 64);
            }
            col /= 26; 
        }
        ans += char (col + 64);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
