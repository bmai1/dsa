class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans, u;
        int f1[1001]{};
        int f2[1001]{};
        for (int n : arr1) f1[n]++;
        for (int n : arr2) f2[n]++;
        for (int n : arr2) {
            int f = f1[n];
            while (f--) ans.push_back(n);
            f1[n] = 0;
        }
        for (int i = 0; i < 1001; ++i) {
            int f = f1[i];
            while (f--) u.push_back(i);
        }
        sort(u.begin(), u.end());
        for (int n : u) ans.push_back(n);
        return ans;
    }
};