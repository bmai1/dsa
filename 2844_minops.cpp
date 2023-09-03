class Solution {
public:
    int minimumOperations(string num) {
        int ans = -1;
        bool zero = false, five = false;
        int fivecnt = 0, zerocnt = 0;
        for (int i = num.size(); i >= 0; --i) {
            if (zero) {
                if (num[i] == '0') return ans + fivecnt;
                if (num[i] == '5') return ans;
            }
            if (five && (num[i] == '2' || num[i] == '7')) return ans + zerocnt + (fivecnt - 1);
            else if (num[i] == '0') { zero = true; ++zerocnt; }
            else if (num[i] == '5') { five = true; ++fivecnt; }
            else ++ans; 
        }
        return ans + fivecnt;
    }
};