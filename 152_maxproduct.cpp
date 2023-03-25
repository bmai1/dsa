class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        if (nums.size() == 1 ) { return nums[0]; }

        int product = 1, max_product = INT_MIN;
        for (int n: nums) {
            product *= n;
            max_product = max(max_product, product);
            if (n == 0) { product = 1; }
        }

        // check from back
        product = 1;
        for (int i = nums.size() - 1; i > 0; --i) {
            product *= nums[i];
            max_product = max(max_product, product);
            if (nums[i] == 0) { product = 1; }
        }

        return max_product;
    }
};
