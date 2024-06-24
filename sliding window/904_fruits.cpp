class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int i = 0, j = 0, n = fruits.size();
        for (; j < n; ++j) {
            m[fruits[j]]++;
            // while (m.size() > 2), res = max(res, j - i + 1)
            if (m.size() > 2) {
                if (--m[fruits[i]] == 0) m.erase(fruits[i]);
                ++i;
            }
        }
        return j - i;
    }
};