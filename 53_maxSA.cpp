class Solution {
private:
    int maxCross(vector<int>& n, int lo, int mid, int hi) {
        int leftSum = 0; // A[i..mid]
        int sum = 0;
        for (int i = mid - 1; i >= lo; --i) {
            sum += n[i];
            leftSum = max(leftSum, sum);
        }
        int rightSum = 0; // A[mid + 1..hi]
        sum = 0;
        for (int j = mid + 1; j <= hi; ++j) {
            sum += n[j];
            rightSum = max(rightSum, sum);
        }
        return leftSum + rightSum + n[mid];
    }
    int maxSA(vector<int>& n, int lo, int hi) {
        if (lo > hi) return INT_MIN; // stops stack-overflow
        if (hi == lo) return n[lo];
        int mid = lo + (hi - lo) / 2;
        int leftSum = maxSA(n, lo, mid - 1);
        int rightSum = maxSA(n, mid + 1, hi);
        int crossSum = maxCross(n, lo, mid, hi);
        return max(crossSum, max(leftSum, rightSum));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return maxSA(nums, 0, nums.size() - 1);
    }
};
