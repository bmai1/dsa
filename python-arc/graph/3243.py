class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        res = []
        
        # init edges
        for i in range(n - 1):
            adj[i].append(i + 1)
        
        # find shortest path from 0 to n - 1
        def dijkstra():
            distance = [float('inf')] * n
            pq = [] # min-heap
            
            distance[0] = 0
            heapq.heappush(pq, (0, 0))  # (distance, city)
            
            while pq:
                dist, city = heapq.heappop(pq)
                if dist > distance[city]:
                    continue
                # update min for adj
                for nxt in adj[city]:
                    new_dist = dist + 1
                    if new_dist < distance[nxt]:
                        distance[nxt] = new_dist
                        heapq.heappush(pq, (new_dist, nxt))
            
            return distance[n - 1]
        
        for u, v in queries:
            adj[u].append(v)
            res.append(dijkstra())
        
        return res