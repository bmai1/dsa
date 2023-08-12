class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> p;
        for (int i = 0; i < nums1.size(); ++i) {
            p.push_back({nums2[i], nums1[i]});
        }
        sort(p.rbegin(), p.rend());
        // for (auto s : p) cout << s.first << ' ' << s.second << endl;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, res = 0;
        for (auto& [n1, n2] : p) {
            pq.emplace(n2); // push without unnecessary copy
            sum += n2;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                res = max(res, sum * n1);
            }
        }
        return res;
    }
};