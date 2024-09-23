class Solution {
private:
    unordered_set<string> st;
    vector<vector<int>> dp;
    int res = INT_MAX;

    // void r(string& s, string curr, int i, int left) {
    //     if (i == s.size()) {
    //         res = min(res, left);
    //         return;
    //     }
        
    //     curr += s[i];
    //     // split
    //     if (st.find(curr) != st.end()) r(s, "", i + 1, left - (int) curr.size());
        
    //     // skip
    //     r(s, curr, i + 1, left);

    //     // skip and clear
    //     r(s, "", i + 1, left);
    // }

    int r(string& s, int i, int left) {
        if (i == s.size()) {
            return left;
        }

        if (dp[i][left] != -1) return dp[i][left];

        string curr;
        int mn = INT_MAX;
        for (int j = i; j < s.size(); ++j) {
            curr += s[j];
            // try split
            if (st.find(curr) != st.end()) {
                mn = min(mn, r(s, j + 1, left - (int) curr.size()));
            }
        }
        // skip
        mn = min(mn, r(s, i + 1, left));

        return dp[i][left] = mn;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        dp.assign(51, vector<int>(51, -1));
        for (string d : dictionary) st.insert(d);
        return r(s, 0, (int) s.size());
    }
};