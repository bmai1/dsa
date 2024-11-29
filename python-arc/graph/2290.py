class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[float('inf')] * n for _ in range(m)]
        visited = [[False] * n for _ in range(m)]
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        q = deque()

        dp[0][0] = 0
        q.appendleft([0, 0])
        visited[0][0] = True

        while q:
            x1, y1 = q.popleft()
            for d in dirs:
                x2 = x1 + d[0]
                y2 = y1 + d[1]
                if x2 >= 0 and y2 >= 0 and x2 < m and y2 < n and not visited[x2][y2]:
                    dp[x2][y2] = dp[x1][y1] + int(grid[x2][y2] == 1)
                    if (grid[x2][y2] == 1):
                        q.append([x2, y2])
                    else:
                        q.appendleft([x2, y2])
                    visited[x2][y2] = True
        
        return dp[m - 1][n - 1]