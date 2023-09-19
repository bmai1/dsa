class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = nums[0]
        fast = nums[0]

        # find meeting point
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break

        # find entrance to cycle 
        slow = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
    
        return slow