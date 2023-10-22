class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums) m[n]++;
        vector<pair<int, int>> v;
        for (auto it : m) v.push_back(it);
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<int> res;
        int n = v.size();
        for (int i = n - 1; i >= n - k; --i) {
            res.push_back(v[i].first);
        }
        return res;

        // unordered_map<int, int> m;
        // for (int n : nums) m[n]++;

        // priority_queue<int> pq; 
        // for (auto it : m) pq.push(it.second);
    
        // vector<int> res;
        // while (k-- && !pq.empty()) {
        //     int f = pq.top(); pq.pop();
        //     for (auto it : m) {
        //         if (it.second == f) {
        //             res.push_back(it.first);
        //             m.erase(it.first);
        //             break;
        //         }
        //     }
        // }
        // return res;
    }
};