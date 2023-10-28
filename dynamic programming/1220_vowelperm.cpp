class Solution {
private:
    int mod = 1e9 + 7;
    unordered_map<char, vector<char>> m;
    unordered_map<char, vector<int>> dp;
    // top down, count remaining
    int dp_helper(int n, char prev) {
        if (!n) return 1;
        if (dp[prev][n]) return dp[prev][n];
        for (auto c : m[prev]) {
            dp[prev][n] = (dp[prev][n] + dp_helper(n - 1, c)) % mod;
        }
        return dp[prev][n];
    }
public:
    int countVowelPermutation(int n) {
        // init valid map
        m['s'] = {'a', 'e', 'i', 'o', 'u'};
        m['a'] = {'e'};
        m['e'] = {'a', 'i'};
        m['i'] = {'a', 'e', 'o', 'u'};
        m['o'] = {'i', 'u'};
        m['u'] = {'a'};

        string vowels = "saeiou";
        for (auto c : vowels) dp[c].resize(n + 1);
        return dp_helper(n, 's');
    }
};

class Solution {
public:
    int countVowelPermutation(int n) {
        // iterative bottom-up
        long long mod = 1e9 + 7;
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        long long n_a, n_e, n_i, n_o, n_u;
        for (int j = 2; j <= n; ++j) {
            n_a = e;
            n_e = (a + i) % mod;
            n_i = (a + e + o + u) % mod;
            n_o = (i + u) % mod;
            n_u = a;
            a = n_a, e = n_e, i = n_i, o = n_o, u = n_u;
        }
        return (a + e + i + o + u) % mod;
    }
};