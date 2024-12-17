class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        dirs = [
            [1, 3],
            [0, 2, 4],
            [1, 5],
            [0, 4],
            [1, 3, 5],
            [2, 4]  
        ]
        solved = [1, 2, 3, 4, 5, 0]
        state = [i for j in board for i in j]
        q = []
        visited = []
        q.append(state)
        visited.append(state)
        swaps = 0
        while len(q) != 0:
            n = len(q)
            for i in range(n):
                curr = q.pop(0)
                if curr == solved:
                    return swaps
                z = curr.index(0)
                for d in dirs[z]:
                    nxt = curr[:] # need to create shallow copy
                    nxt[z], nxt[d] = nxt[d], nxt[z]
                    if nxt not in visited:
                        q.append(nxt)
                        visited.append(nxt)
            swaps += 1
        return -1