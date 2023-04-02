class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0

        dp = [0] * n  # dp[i] stores the number of arithmetic slices ending at i
        for i in range(2, n):
            if nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]:
                dp[i] = dp[i - 1] + 1
        return sum(dp)

        # O(n^3) TLE
        # # arithmetic check
        # def ar(nums):
        #     diff = nums[1] - nums[0]
        #     for i, n in enumerate(nums[1:], start=1):
        #         if nums[i] - nums[i - 1] != diff:
        #             return False
        #     return True

        # ans = 0
        # # go through sublists
        # for i in range(len(nums) + 1):
        #     for j in range(i):
        #         sublist = nums[j: i]
        #         if len(sublist) >= 3 and ar(sublist) == True:
        #             ans += 1
        # return ans
            
            
