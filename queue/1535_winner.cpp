class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k == 1) return max(arr[0], arr[1]);
        if (k >= arr.size() - 1) return *max_element(arr.begin(), arr.end());

        queue<int> q;
        for (auto n : arr) q.push(n);
        int curr = 0;
        while (true) {
            int f = q.front(); q.pop();
            if (f > q.front()) {
                if (++curr == k) return f;
                q.push(q.front());
                q.front() = f;  
            }
            else {
                curr = 1;
                q.push(f);
            }
        }
        return -1;
    }
};