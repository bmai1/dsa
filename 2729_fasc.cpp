class Solution {
public:
    bool isFascinating(int n1) {
        unordered_map<int, int> m;
        int n2 = 2 * n1, n3 = 3 * n1;
        while (n1 || n2 || n3) {
            m[n1 % 10]++, m[n2 % 10]++, m[n3 % 10]++;
            n1 /= 10, n2 /= 10, n3 /= 10;
        }
        return !m[0] && m.size() == 10;
    }
};