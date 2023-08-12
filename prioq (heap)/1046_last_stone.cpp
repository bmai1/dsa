class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> pq(begin(s), end(s));
        while (pq.size() > 1) {
            int tmp = pq.top(); pq.pop();
            int tmp2 = pq.top(); pq.pop();
            if (tmp > tmp2) { pq.push(tmp - tmp2); }
        }
        return pq.empty() ? 0 : pq.top();
    }
    
    // // unoptimized vector sort loop
    // // max element = stones.front()
    //     while (s.size() > 1) {
    //         sort(s.begin(), s.end());
    //         int n = s.size();
    //         // x == y
    //         if (s[n - 1] == s[n - 2]) {
    //             s.pop_back();
    //             s.pop_back();
    //         }
    //         // x < y
    //         else {
    //             s[n - 2] = s[n - 1] - s[n - 2];
    //             s.pop_back();
    //         }
    //     }
    //     return s.empty() ? 0 : s[0]; 
};
