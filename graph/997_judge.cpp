class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n + 1);
        for (auto t : trust) {
            count[t[0]]--;
            count[t[1]]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (count[i] == n - 1) return i;
        }
        return -1;
        
        // if (n == 1) return 1;
        // unordered_map<int, int> m;
        // for (auto t : trust) {
        //     m[t[0]] = -1; // judge can't trust
        //     if (m[t[1]] != -1) m[t[1]]++; 
        // }
        // int judge = -1;
        // for (auto it : m) {
        //     if (it.second == n - 1) {
        //         if (mayor == -1) judge = it.first;
        //         else return -1; // must have only one
        //     }
        // }
        // return judge;
    }
};