class Solution {
public:
    int minimumPossibleSum(int n, int target) { 
        long long k = target / 2;
        if (n <= k)
            return 1L * n * (n + 1) / 2;
        return (k * (k + 1) / 2 + ((long long) target + target + n - k - 1) * (n - k) / 2) % (long long) (1e9 + 7);

        // unordered_set<int> s; 
        // long long m = 0;
        // int j = n;
        // for (int i = 1; i <= j; ++i) {
        //     if (s.find(target - i) == s.end()) { 
        //         s.insert(i); 
        //         m += i;
        //     }
        //     else ++j;
        // }
        // return m % (long long) (1e9 + 7);
    }
};