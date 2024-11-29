class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[inf] * n for _ in range(m)]
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        q = deque()

        dp[0][0] = 0
        q.appendleft([0, 0])

        while q:
            x1, y1 = q.popleft()
            for dx, dy in dirs:
                x2, y2 = x1 + dx, y1 + dy
                if x2 >= 0 and y2 >= 0 and x2 < m and y2 < n and dp[x2][y2] == inf:
                    if (grid[x2][y2] == 1):
                        dp[x2][y2] = dp[x1][y1] + 1
                        q.append([x2, y2])
                    else:
                        dp[x2][y2] = dp[x1][y1]
                        q.appendleft([x2, y2])
        
        return dp[m - 1][n - 1]