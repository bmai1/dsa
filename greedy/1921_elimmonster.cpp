class Solution {
    void elimClose(vector<int>& dist, vector<int>& speed) {
        int min_d = INT_MAX, min_s = INT_MAX, n = dist.size(), index = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] < min_d || (dist[i] == min_d && speed[i] < min_s)) {
                index = i;
                min_d = dist[i];
                min_s = speed[i];
            }
        }
        dist[index] = INT_MAX;
    }
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for (int i = 0; i < n; ++i) {
            dist[i] = (dist[i] - 1) / speed[i];
        }
        sort(dist.begin(), dist.end());
        for (int i = 0; i < n; ++i) {
            if (i > dist[i]) return i;
        }
        return n;
    
        // int n = dist.size(), elim = 0;
        // for (int i = 0; i < n; ++i) {
        //     // elim closest
        //     elimClose(dist, speed);
        //     for (int j = 0; j < n; ++j) {
        //         dist[j] -= speed[j];
        //         if (dist[j] <= 0) return i + 1;
        //     }

        // }
        // return n;
    }
};