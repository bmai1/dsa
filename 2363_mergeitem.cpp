class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ret;
        int items[1001] = {};

        for (auto i : items1) 
            items[i[0]] += i[1];

        for (auto i : items2) 
            items[i[0]] += i[1];

        for (int i = 0; i < 1001; ++i) 
            if (items[i]) ret.push_back({i, items[i]});
        
        return ret;
    }
};