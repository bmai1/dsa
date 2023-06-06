class Solution {
private:
    void dfs(vector<int> &ans, vector<int> &spells, vector<int> &potions, long long success, int i, int j) {
        if (j < 0 || j >= potions.size()) { return; }
        if ((long long) spells[i] * potions[j] >= success) { ++ans[i]; }
        dfs(ans, spells, potions, success, i, j + 1);
        // dfs(ans, spells, potions, success, i, j - 1); <-- keeps recursively calling without marking, stack-overflow
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // vector<int> ans(spells.size(), 0);
        // for (int i = 0; i < spells.size(); ++i) {
        //     dfs(ans, spells, potions, success, i, 0);
        // }
        // return ans; 
        vector<int> ans(spells.size(), 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); ++i) {
            // find first potion index that multiplies with spells[i] to be equal or greater than success
            // *lower_bound is usable with a clever equation
            // for (int j = 0; j < potions.size(); ++j) {
            //     if ((long long) spells[i] * potions[j] >= success) { 
            //         ans.push_back(potions.size() - j); 
            //         break;
            //     }
            //     else if (j == potions.size() - 1) { ans.push_back(0); }
            // }
            
            int lo = 0, hi = potions.size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if ((long long int) spells[i] * (long long int) potions[mid] >= success) { hi = mid - 1; }
                else { lo = mid + 1; }
            }
            ans[i] = potions.size() - hi - 1;
        }
        return ans;
    }
};
