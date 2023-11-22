class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> ans;
        vector<bool> visited(n, false);
        int i = 1, curr = 0;
        while (true) {
            if (visited[curr]) break;
            visited[curr] = true;
            curr = (curr + i++ * k) % n;
        }
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) ans.push_back(i + 1);
        }
        return ans;
    }
};