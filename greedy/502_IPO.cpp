class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // int n = capital.size();
        // map<int, priority_queue<int>> m;

        // for (int i = 0; i < n; ++i) {
        //     m[capital[i]].push(profits[i]);
        // }

        // for (int i = 0; i < n && i < k; ++i) {
        //     int mx = 0, c = -1;
        //     for (auto &it : m) {
        //         if (w >= it.first) {
        //             if (mx <= it.second.top()) {
        //                 mx = it.second.top();
        //                 c = it.first;
        //             }
        //         }
        //         else break; // not enough capital
        //     }
        //     if (mx == 0) break; // no more available profit
        //     if (c != -1) {
        //         m[c].pop();
        //         if (m[c].empty()) m.erase(c);
        //     }
        //     w += mx;
        // }
        // return w;

        int n = capital.size();
        vector<pair<int, int>> ps;
        for (int i = 0; i < n; ++i) {
            ps.push_back({capital[i], profits[i]});
        }
        sort(ps.begin(), ps.end()); // greedy sort by capital required
        priority_queue<int> pq;
        int i = 0;
        for (int j = 0; j < n && j < k; ++j) {
            while (i < n && ps[i].first <= w) {
                pq.push(ps[i].second);
                ++i;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};