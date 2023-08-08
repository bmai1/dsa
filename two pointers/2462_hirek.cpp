class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        long long ans = 0; 
        int lo = 0, hi = costs.size() - 1;
        while (k--) {
            while (pq1.size() < candidates && lo <= hi) pq1.push(costs[lo++]);
            while (pq2.size() < candidates && lo <= hi) pq2.push(costs[hi--]);
            int a = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int b = pq2.size() > 0 ? pq2.top() : INT_MAX;
            if (a <= b) { ans += a; pq1.pop(); }
            else { ans += b; pq2.pop(); }
        }
        return ans;
    }
};