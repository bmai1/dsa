class Solution {
    int[] dp = new int [31];
    public int fib(int n) {
        // dp top-down
        if (n <= 1) { return n; }
        if (dp[n] != 0) { return dp[n]; }
        else { return dp[n] = fib(n - 1) + fib(n - 2); }
        
        // // iterative
        // if (n <= 1) { return n; }
        // int a = 1, b = 1;
        // while (--n > 0) {
        //     a = (b += a) - a;
        // }
        // return a;
    }
}
