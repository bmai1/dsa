class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // unordered_set<int> s;
        // int max_seen = -1, parts = 0;

        // for (int i = 0; i < arr.size(); ++i) {
        //     s.insert(arr[i]);
        //     max_seen = max(max_seen, arr[i]);

        //     bool sorted = true;
        //     for (int j = 0; j < max_seen; ++j) {
        //         if (!s.contains(j)) {
        //             sorted = false;
        //             break;
        //         }
        //     }

        //     if (sorted) ++parts;
        // }

        // return parts;

        // int parts = 0, max_seen = -1;
        // for (int i = 0; i < arr.size(); ++i) {
        //     max_seen = max(max_seen, arr[i]);
        //     parts += max_seen == i;
        // }
        // return parts;

        stack<int> stk;
        for (int n : arr) {
            int mx = n;
            while (!stk.empty() && stk.top() > n) {
                mx = max(mx, stk.top());
                stk.pop();
            }
            stk.push(mx);
        }
        return stk.size();
    }
};
