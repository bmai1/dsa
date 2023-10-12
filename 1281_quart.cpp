class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cnt = 1, n = arr.size(), pre = arr[0];
        for (int i = 1; i < n; ++i) {
            cnt = arr[i] == pre ? cnt + 1 : 1;
            if (cnt > n / 4) return arr[i];
            pre = arr[i];
        }
        return arr[0];
    }
};