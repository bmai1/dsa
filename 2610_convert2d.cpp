class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<vector<int>> ans;
        for (int num: nums) { m[num]++; }
        while (true) {
            bool empty = true;
            vector<int> row;
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (it->second != 0) {
                    --it->second;
                    row.push_back(it->first);
                    empty = false;
                }
            }
            if (empty == true) { break; }
            ans.push_back(row);
        }
        return ans; 
    }
};
