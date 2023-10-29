class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        unordered_map<int, int> visited;
        visited[rounds[0]]++;
        int start, end, j;
        for (int i = 1; i < rounds.size(); ++i) {
            start = rounds[i - 1]; 
            end = rounds[i];
            if (end > start) {
                // doesn't visit start 
                // [1,3] -> 2++, 3++; [1,2] -> 2++;
                for (j = start + 1; j <= end; ++j) visited[j]++;   
            }
            else {
                // [3,1] -> 4++, 1++;
                for (j = start + 1; j <= n; ++j) visited[j]++;
                for (j = 1; j <= end; ++j) visited[j]++;
            }
        }

        vector<int> ans;
        int m_visit = 0;
        for (auto it : visited) {
            // cout << it.first << ' ' << it.second << endl;
            if (it.second > m_visit) {
                m_visit = it.second;
                ans.clear();
                ans.push_back(it.first);
            }
            else if (it.second == m_visit) ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};