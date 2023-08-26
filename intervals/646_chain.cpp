class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; 
        });
        // for (auto p : pairs) {
        //     for (auto n : p) { cout << n << ' '; }
        //     cout << endl;
        // }
        int ans = 1, i = 0, prev = pairs[0][1];
        while (i < pairs.size() - 1) {
            if (prev < pairs[++i][0])  {
                prev = pairs[i][1];
                ++ans;
            }
        }
        return ans;
    }
};