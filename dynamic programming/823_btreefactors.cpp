class Solution {
private:
    int mod = 1e9 + 7;
    unordered_map<int, long long> trees;
    unordered_set<int> s;

    long long build(vector<int>& arr, int n) {
        if (trees.find(n) != trees.end()) return trees[n];
        long long total = 1;
        for (int f1 : arr) {
            if (f1 > n) break;
            if (n % f1 == 0 && s.find(n / f1) != s.end()) {
                total = (total + (build(arr, f1) * build(arr, n / f1)) % mod) % mod;
            }
        }
        trees[n] = total;
        return total;
    }

public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        // has to be top down
        // find two factors for each parent
        sort(arr.begin(), arr.end());
        long long res = 0;
        for (int n : arr) s.insert(n);
        for (int n : arr) res = (res + build(arr, n)) % mod;
        return res;
    }
};