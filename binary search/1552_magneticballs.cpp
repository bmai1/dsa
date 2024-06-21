class Solution {
private:
    int count(vector<int>& pos, int d) {
        int res = 1, curr = pos[0];
        for (int i = 1; i < pos.size(); ++i) {
            if (pos[i] - curr >= d) {
                ++res;
                curr = pos[i];
            }
        }
        return res;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 0, hi = position.back() - position.front();
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (count(position, mid) >= m) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};