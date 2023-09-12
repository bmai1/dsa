class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int mdiff = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; ++i) {
            int d = abs(arr[i] - arr[i + 1]);
            if (mdiff > d) {
                mdiff = d;
                ans.clear();
                ans.push_back({arr[i], arr[i + 1]});
            }
            else if (mdiff == d) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};