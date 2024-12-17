class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        neg, total, mn = 0, 0, 100000

        for row in matrix:
            for col in row:
                neg += col < 0
                total += abs(col)
                mn = min(mn, abs(col))

        # even negatives cancel, otherwise subtract min twice
        return total if neg % 2 == 0 else total - 2 * mn