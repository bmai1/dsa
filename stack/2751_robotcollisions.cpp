class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> res;
        vector<pair<int, int>> pos;
        int n = positions.size();
        for (int i = 0; i < n; ++i) {
            pos.push_back({positions[i], i});
        }
        sort(pos.begin(), pos.end());

        stack<int> s;
        for (auto& [p, i] : pos) {
            if (directions[i] == 'R') s.push(i);
            else {
                while (!s.empty() && healths[i]) {
                    int j = s.top();
                    if (healths[i] > healths[j]) {
                        healths[i]--;
                        healths[j] = 0;
                        s.pop();
                    }
                    else if (healths[i] < healths[j]) {
                        healths[j]--;
                        healths[i] = 0;
                    }
                    else {
                        healths[i] = 0;
                        healths[j] = 0;
                        s.pop();
                    }
                }
            }
        }

        for (int h : healths) if (h) res.push_back(h);
        return res;
    }
};