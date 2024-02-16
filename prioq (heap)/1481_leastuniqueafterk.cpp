class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int n : arr) ++m[n];

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : m) pq.push(it.second);

        while (!pq.empty() && k >= pq.top()) {
            k -= pq.top();
            pq.pop();
        }

        return pq.size();
    } 
};