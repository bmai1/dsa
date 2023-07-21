class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0; 
        sort(g.begin(), g.end());
        map<int, int> cookies;
        for (int size : s) cookies[size]++;
        for (int i = 0; i < g.size(); ++i) {
            int greed = g[i];
            for (auto it = cookies.begin(); it != cookies.end(); ++it) {
                if (it->first >= greed) { 
                    it->second--; 
                    if (it->second == 0) { cookies.erase(it->first); }
                    ++ans; 
                    break; 
                }
            }
            if (cookies.empty()) break;
        }
        return ans;

        if (s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) ++i;
            ++j;
        }
        return i;
    }
};