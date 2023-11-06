class Solution {
public:
    int minOperations(string s) {
        char f1 = '1', f0 = '0';
        int r1 = 0, r2 = 0;
        for (auto c : s) {
            r1 += c != f1;
            r2 += c != f0;
            swap(f1, f0);
        }
        return min(r1, r2);
    }
};