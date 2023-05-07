class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        // pad sides to check all cases
        f.insert(f.begin(), 0);
        f.push_back(0);
        int open = 0;
        for (int i = 1; i < f.size() - 1; ++i) {
            if (open >= n) { break; }
            if (f[i] + f[i - 1] + f[i + 1] == 0) { 
                f[i] = 1;
                ++open;
            }
        }
        return open >= n;
    }
};
