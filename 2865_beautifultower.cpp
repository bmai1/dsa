class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        int n = maxHeights.size();
        for (int i = 0; i < n; ++i) {      
            long long sum = maxHeights[i]; // declare peak
            long long tmp = sum, prev = sum;
            for (int j = i - 1; j >= 0; --j) {
                prev = min((long long) maxHeights[j], prev);
                sum += prev;
            }
            prev = tmp;
            for (int j = i + 1; j < n; ++j) {
                prev = min((long long) maxHeights[j], prev);
                sum += prev;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};