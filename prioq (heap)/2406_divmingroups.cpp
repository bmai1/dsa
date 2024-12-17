class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& i : intervals) {
            if (!pq.empty() && pq.top() < i[0]) pq.pop();
            pq.push(i[1]);
        }
        return pq.size();
    }
};