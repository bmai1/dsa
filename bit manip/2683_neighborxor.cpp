class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n);
        original[0] = 0;

        for (int i = 1; i < n; ++i) {
            // swaps bit when derived[i] differs from original[i - 1]
            original[i] = derived[i] ^ original[i - 1];
        }

        return original[0] ^ original[n - 1] == derived[0];
    }
};
