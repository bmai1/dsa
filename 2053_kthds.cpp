class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for (auto s : arr) ++m[s];
        int i{};
        for (auto s : arr) if (m[s] == 1 && ++i == k) return s;
        return "";
    }
};