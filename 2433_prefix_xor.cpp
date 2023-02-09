class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // iterate through vector
        for (int i = pref.size() - 1; i > 0; --i) {
            // xor prefix, pref[i] = arr[0] ^ arr[1] ^ arr[i]
            pref[i] ^= pref[i - 1];
        }
        return pref;
    }
};
