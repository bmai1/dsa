class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        res = [['.'] * m for _ in range(n)]

        for i in range(m):
            max_row = n - 1
            for j in reversed(range(n)):
                if box[i][j] == '#':
                    res[max_row][m - i - 1] = '#'
                    max_row -= 1
                elif box[i][j] == '*':
                    res[j][m - i - 1] = '*'
                    max_row = j - 1

        return res