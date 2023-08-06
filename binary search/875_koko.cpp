class Solution {
private:
    bool eat(vector<int>& piles, int k, int h) {
        int time = 0;
        for (int pile : piles) {
            time += 1 + (pile - 1) / k;
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        if (h == n) return hi;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (eat(piles, mid, h)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};