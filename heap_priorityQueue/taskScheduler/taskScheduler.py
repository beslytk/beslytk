import heapq
from typing import Counter, Deque, List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:        
        # python object Counter to auto count the list item freq
        count = Counter(tasks)
        # workaround since python only have minHeap
        maxHeap = [-cnt for cnt in count.values()]
        heapq.heapify(maxHeap) # sort them
        
        time = 0
        q = Deque() # pairs of [-cnt, idleTime]
        while maxHeap or q:
            time += 1 # each iteration schedules 1 task as per rule
            
            if not maxHeap:
                time = q[0][1]
            else:
                # decrement the count # adding 1 since heap contains negative values
                cnt = 1 + heapq.heappop(maxHeap) 
                if cnt:
                    q.append([cnt, time + n]) # currTime +idleTime => nextTime to appear in prioQue
            if q and q[0][1] == time:
                heapq.heappush(maxHeap,  q.popleft()[0])
        return time