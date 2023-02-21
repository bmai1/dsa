class Solution {
public:
    static bool sortByVal(const pair<string, int> &a, const pair<string, int> &b) {
        // alphabetical sort
        if (a.second == b.second) { return a.first < b.first; }
        // value sort
        return (a.second > b.second); 
    } 
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans(k);
        unordered_map<string, int> m; 
        for (auto word: words) { m[word]++; }
        vector<pair<string, int>> freq;
        for (auto it = m.begin(); it != m.end(); ++it) {
            freq.push_back(make_pair(it->first, it->second));
        }
        sort(freq.begin(), freq.end(), sortByVal);
        for (int i = 0; i < k; ++i) {
            ans[i] = freq[i].first;
        }
        return ans;
    }
};
