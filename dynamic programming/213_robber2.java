class Solution {
    private int r(int[] nums) {
        int a = 0, b = 0, ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            ans = Math.max(b + nums[i], a);
            b = a;
            a = ans;
        }
        return ans;
    }
    public int rob(int[] nums) {
        if (nums.length == 1) { return nums[0]; }
        int[] t1 = Arrays.copyOfRange(nums, 0, nums.length - 1);
        int[] t2 = Arrays.copyOfRange(nums, 1, nums.length);
        return Math.max(r(t1), r(t2));
    }
}
