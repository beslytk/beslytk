from typing import List
# Eg:
#     ______________
#    |              |
#    |              v
#   'A'---->'B'--->'C'
#
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        adj = {char: set() for word in words for char in word}
        # Build graph adjacency list
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            minLen = min(len(w1), len(w2))
            if len(w1) > len(w2) and w1[:minLen] == w2[:minLen]:
                return ""
            for j in range(minLen):
                if w1[j] != w2[j]:
                    print(w1[j], w2[j])
                    adj[w1[j]].add(w2[j])
                    break
        # {char: bool} False=processed, True=in current path
        visited = {}  
        res = []
        # postOrder dfs (Topological Sort)
        def dfs(char):
            if char in visited:
                return visited[char]

            visited[char] = True

            for neighChar in adj[char]:
                if dfs(neighChar):
                    return True

            visited[char] = False
            res.append(char)
        
        # for each key (char) in hashMap, run dfs
        for char in adj:
            if dfs(char): # if True, cycle detected
                return ""
        # reverse the list as result constructed in postOrder
        res.reverse()
        return "".join(res)