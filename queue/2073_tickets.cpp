class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for (int i = 0; i < tickets.size(); ++i) q.push(i); // position order
        int time = 0;
        while (tickets[k] > 0) {
            int curr = q.front();
            --tickets[curr], ++time;
            if (tickets[curr] > 0) q.push(q.front());
            q.pop(); 
        }
        return time;
    }
};