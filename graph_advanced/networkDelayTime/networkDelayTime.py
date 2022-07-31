import collections
import heapq
from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # adjacency list with pair (node, weight)
        edges = collections.defaultdict(list)
        # u=source v=dest w=time
        for u, v, w in times:
            edges[u].append((v, w))
        # start with source node in minHeap
        minHeap = [(0, k)]
        visit = set()
        t = 0
        while minHeap:
            w1, n1 = heapq.heappop(minHeap)
            # skip for 2nd encounter
            if n1 in visit:
                continue
            visit.add(n1)
            t = max(t, w1)

            for n2, w2 in edges[n1]:
                if n2 not in visit:
                    heapq.heappush(minHeap, (w1 + w2, n2))
        return t if len(visit) == n else -1

sol = Solution()
times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4
k = 2
out = sol.networkDelayTime(times, n, k)        
print("max required time to reach all nodes is: {}".format(out))