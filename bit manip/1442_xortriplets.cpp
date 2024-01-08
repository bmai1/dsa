class Solution {
private:
    int x(vector<int>& xor_p, int i, int j) {
        if (i == 0) return xor_p[j];
        return xor_p[j] ^ xor_p[i - 1];
    }
public:
    int countTriplets(vector<int>& arr) {
        // O(N^4) Brute Force
        // int res = 0, n = arr.size();
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         for (int k = j; k < n; ++k) {
        //             // xor i to j - 1
        //             int a = arr[i];
        //             for (int l = i + 1; l < j; ++l) {
        //                 a ^= arr[l];
        //             }
        //             // xor j to k
        //             int b = arr[j];
        //             for (int l = j + 1; l <= k; ++l) {
        //                 b ^= arr[l];
        //             }
        //             if (a == b) ++res;
        //         }
        //     }
        // }
        // return res;

        // O(N^3) Brute Force with Prefix
        // int n = arr.size(), res = 0;
        // vector<int> xor_p(n);

        // xor_p[0] = arr[0];
        // for (int i = 1; i < n; ++i) {
        //     xor_p[i] = xor_p[i - 1] ^ arr[i];
        // }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         for (int k = j; k < n; ++k) {
        //             if (x(xor_p, i, j - 1) == x(xor_p, j, k)) ++res;
        //         }
        //     }
        // }

        // O(N^2) Prefix correctly
        arr.insert(arr.begin(), 0);
        int n = arr.size(), res = 0;

        for (int i = 1; i < n; ++i) {
            arr[i] ^= arr[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] == arr[j]) {
                    res += j - i - 1;
                }
            }
        }

        return res;
    }
};