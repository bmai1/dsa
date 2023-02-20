class Solution {
public:
    int characterReplacement(string s, int k) {
        // maxCount of substr so far, maxLength of window
        int n = s.size(), left = 0, maxCount = 1, maxLength = 0;
        vector<int> freq(26, 0);
        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);
            if (right - left + 1 - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            // length of window changes size, because it doesn't depend on k swaps
            maxLength = max(maxLength, right - left + 1);
        }
        // return max window length
        return maxLength;
    }
};
