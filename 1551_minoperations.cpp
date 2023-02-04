class Solution {
public:
    int minOperations(int n) {
        // arr[i] = (2 * i) + 1; odd numbers
        if (n == 1) { return 0; }
        // when even, min operations is (n / 2)^2
        if (n % 2 == 0) { return pow(n / 2, 2); }
        // else total is increasing by (n - 1)
        return minOperations(n - 2) + (n - 1);
        // no recursion: 
        // return (n / 2) * (n / 2 + 1);
    }
};
