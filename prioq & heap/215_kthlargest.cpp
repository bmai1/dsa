class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        // for (int n : nums) pq.push(n);
        // while (k-- != 1) pq.pop();
        // return pq.top();

        // reverse priority queue
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};