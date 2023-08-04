class Solution {
private:
    bool searchVector(vector<int>& v, int target) {
        int lo = 0, hi = v.size();
        while (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            if (v[mid] == target) { return true; }
            if (v[mid] < target) { lo = mid + 1; }
            else { hi = mid; }
        }
        return false; 
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // // m rows, n cols
        // int m = matrix.size(), n = matrix[0].size();
        // int start = 0, end = m * n - 1;
        // while (start <= end) {
        //     int mid = (start + end) / 2;
        //     int curr = matrix[mid / n][mid % n];
        //     if (curr == target) { return true; }
        //     else if (curr > target) { end = mid - 1; }
        //     else if (curr < target) { start = mid + 1; }
        // }
        // return false;


        // for (int i = 0; i < matrix.size(); ++i) {
        //     for (int j = 0; j < matrix[0].size(); ++j) {
        //         if (matrix[i][j] == target) { return true; }
        //     }
        // }
        // return false;
        for (auto v: matrix) {
            if (searchVector(v, target) == true) { return true; }
        }
        return false;
    }
};
