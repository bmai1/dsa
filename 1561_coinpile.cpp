class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // pick smallest for bob
        int res = 0;
        sort(piles.begin(), piles.end());
        deque<int> d(piles.begin(), piles.end());
        while (!d.empty()) {
            d.pop_back();
            res += d.back();
            d.pop_back();
            d.pop_front();
        }
        return res;
    }
};