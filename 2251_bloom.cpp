class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& fl, vector<int>& ppl) {
        // int n = p.size();
        // vector<int> ans(n);
        // for (int i = 0; i < n; ++i) {
        //     for (auto f : fl) {
        //         ans[i] += (p[i] >= f[0] && p[i] <= f[1]);
        //     }
        // }
        // return ans;

        // sort(fl.begin(), fl.end(), [](vector<int>& a, vector<int>& b) {
        //     return a[0] < b[0];
        // });
        // // sort(p.begin(), p.end());
        // map<int, int> m; // tracks changes in blooming
        // priority_queue<int, vector<int>, greater<int>> pq;
        // int n = p.size();
        // vector<int> ans(n);
        // for (int i = 0; i < fl.size(); ++i) {

        //     pq.push(fl[i][1]);
        //     m[fl[i][0]] = pq.size();   
        //     while (!pq.empty() && fl[i][0] > pq.top()) {
        //         m[pq.top() + 1] = pq.size() - 1;
        //         pq.pop();
        //     }
        // }
        // // while (!pq.empty()) {
        // //     // check final ends
        // //     m[pq.top() + 1] = pq.size() - 1;;
        // //     pq.pop();
        // // }

        // for (auto it : m) cout << it.first << ' ' << it.second << endl;
        // for (int i = 0; i < n; ++i) {
        //     if (m[p[i]]) ans[i] = m[p[i]];
        //     else {
        //         auto it = m.lower_bound(p[i]);
        //         if (it != m.begin()) --it;
        //         // cout << it->first << endl;
        //         ans[i] = it->second;
        //     }
        // }
        // return ans;
        
        vector<int> p(ppl.begin(), ppl.end());
        sort(p.begin(), p.end());
        sort(fl.begin(), fl.end());
        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0, n = fl.size();
        for (int person : p) {
            // push endings
            while (i < n && fl[i][0] <= person) pq.push(fl[i++][1]);
            while (!pq.empty() && pq.top() < person) pq.pop();
            m[person] = pq.size();
        }

        vector<int> ans;
        for (int person : ppl) ans.push_back(m[person]);
        return ans;
    }
};
