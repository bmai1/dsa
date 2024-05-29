class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int diff = 0;
        for (int i = 0; i < k; ++i) {
            diff += abs(x - arr[i]);
        }

        int start = 0, min_diff = diff;
        for (int i = k; i < arr.size(); ++i) {
            diff = diff - abs(x - arr[i - k]) + abs(x - arr[i]);
            if (diff < min_diff) {
                start = i - k + 1;
                min_diff = diff;
            }
        }

        // doesn't work with duplicates
        // while (end < arr.size() && abs(x - arr[end]) < abs(x - arr[start])) {
        //     ++start;
        //     ++end;
        // }

        vector<int> res;
        for (int i = start; i < start + k; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }
};