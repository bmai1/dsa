class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (int i = 0; i < arr1.size(); ++i) {
            int check = 0;
            for (int j = 0; j < arr2.size(); ++j) {
                if (abs(arr1[i] - arr2[j]) <= d) { check++; }
            }
            if (check == 0) {
                ans++;
            }
        }
        return ans;
    }
};
