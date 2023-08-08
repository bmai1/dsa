class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []
        def bt(arr, curr, idx):
            if (curr < 0):
                return
            if (curr == 0):
                ans.append(arr.copy())
                return
            for i in range(idx, len(candidates)):
                if i > idx and candidates[i] == candidates[i - 1]:
                    continue
                arr.append(candidates[i])
                bt(arr, curr - candidates[i], i + 1)
                arr.pop()
        arr = []
        bt(arr, target, 0)
        return ans