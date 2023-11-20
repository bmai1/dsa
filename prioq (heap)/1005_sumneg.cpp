class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // always flip the minimum element
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int t, sum = accumulate(nums.begin(), nums.end(), 0);
        while (k--) {
            t = pq.top(); pq.pop();
            sum -= 2 * t; // swap sign (e.g. 3 -> -3 is -6)
            pq.push(-t);
        }
        return sum;
    }
};