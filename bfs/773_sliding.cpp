class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string solved = "123450";

        // 012345 -> 102345 or 312045           (swap with 1 or 3)
        // 102345 -> 012345 or 120345 or 142305 (swap with 0, 2, or 4)
        // 120345 -> 102345 or 125340           (swap with 1 or 5)
        // ...
        vector<vector<int>> dirs = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };
        queue<string> q;
        unordered_set<string>visited;

        // flatten board
        string s = "";
        for (auto r : board) {
            for (int c : r) {
                s += to_string(c);
            }
        }
        q.push(s);
        visited.insert(s);

        int swaps = 0;
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string curr = q.front(); q.pop();
                if (curr == solved) return swaps;
                int z = curr.find('0');
                for (int dir : dirs[z]) {
                    string tmp = curr;
                    swap(tmp[z], tmp[dir]);
                    if (visited.contains(tmp)) continue;
                    q.push(tmp);
                    visited.insert(tmp);
                }
            }
            ++swaps;
        }
        return -1;
    }
};