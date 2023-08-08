class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        combos = []
        combo = []

        def backtrack(combo, curr, start):
            if curr < 0 or len(combo) > k:
                return
            if curr == 0 and len(combo) == k:
                tmp = sorted(combo)
                if not tmp in combos:
                    combos.append(tmp)
                return
            for i in range(start, 10):
                if i in combo:
                    continue
                combo.append(i)
                backtrack(combo, curr - i, start + 1)
                combo.pop()
            
        backtrack(combo, n, 1)
        return combos