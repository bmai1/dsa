class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& vals) {
        // sort(vals.begin(), vals.end(), [](vector<int> a, vector<int> b) {
        //     return a[1] < b[1];
        // });

        // int end = vals[0][1];
        // int cnt = 1;
        // for (int i = 1; i < vals.size(); ++i) {
        //     if (vals[i][0] >= end) {
        //         end = vals[i][1];
        //         ++cnt;
        //     }
        // }
        // return vals.size() - cnt;

        sort(vals.begin(), vals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        int cnt = 0, p = 0;
        for (int i = 1; i < vals.size(); ++i) {
            // check overlap such that curr start before prev end
            if (vals[i][0] < vals[p][1]) {
                ++cnt;
                // keep earlier ending interval
                if (vals[i][1] < vals[p][1]) p = i;
            }
            else p = i;
        }
        return cnt;
    }
};