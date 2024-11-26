class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        win = [True] * n
        for edge in edges:
            # mark losers
            win[edge[1]] = False
        
        champ = -1
        for i in range(n):
            if win[i]:
                if champ == -1:
                    champ = i
                else:
                    return -1

        return champ