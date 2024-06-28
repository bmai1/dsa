class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> f;
        for (auto r : roads) {
            f[r[0]]++;
            f[r[1]]++;
        }

        long long res = 0;
        vector<long long> v;
        for (auto it : f) v.push_back(it.second);
        sort(v.rbegin(), v.rend());
        for (auto i : v) {
            res += i * n--;
        }
        return res;
    }
};