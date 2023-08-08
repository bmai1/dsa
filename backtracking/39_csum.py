class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def backtrack(arr, curr, idx):
            if (curr < 0):
                return
            if (curr == 0):
                ans.append(arr.copy())
                return
            for i in range(idx, len(candidates)):
                arr.append(candidates[i])
                backtrack(arr, curr - candidates[i], i)
                arr.pop()
        arr = []
        backtrack(arr, target, 0)
        return ans