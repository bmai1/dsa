class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q; 
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
        int t1, t2;
        for (int i = 0; i < n - 1; ++i) {
            t1 = k;
            while (t1 > 1) {
                t2 =  q.front();
                q.pop();
                q.push(t2);
                --t1;
            }
            q.pop();
        }
        return q.front();
    }
};