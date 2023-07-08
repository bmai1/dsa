class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            int y = startPos[0], x = startPos[1];
            int cnt = 0;
            for (int j = i; j < s.size(); ++j) {
                if (s[j] == 'L') --x;
                else if (s[j] == 'R') ++x;
                else if (s[j] == 'U') --y;
                else if (s[j] == 'D') ++y;
                if (x < 0 || y < 0 || x > n - 1 || y > n - 1) {
                    break;
                }
                ++cnt;   
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
