#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Prim's Algorithm 
    Given array of points, return min cost to connect all points
    All points have 1 path b/w them, cost is Manhattan distance

    Minimum Spanning Tree(MST) problem,
    Prim's Algorithm , greedily pick node not in MST & has smallest edge cost
    Add to MST, & for all its neighbors, try to update min dist values, repeat

    Time: O(n^2)
    Space: O(n)
    https://leetcode.com/problems/min-cost-to-connect-all-points/
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int edgesUsed = 0;
        // track visited nodes
        vector<bool> inMST(n);
        vector<int> minDist(n, INT_MAX);
        
        minDist[0] = 0;         // first point added without any cost
        
        int result = 0;
        
        while (edgesUsed < n) {
            int currMinEdge = INT_MAX; // reset the "currMinEdge" for this iteration
            int currNode = -1;
            
            // greedily pick lowest cost node not in MST
            // first iteration 0th node meets criteria
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && currMinEdge > minDist[i]) {
                    currMinEdge = minDist[i];               // find the node with min edge distance to points in "inMST"
                    currNode = i;
                }
            }
            
            result += currMinEdge;
            edgesUsed++;
            inMST[currNode] = true;
            
            // update adj nodes of curr node
            for (int i = 0; i < n; i++) {
                // manhattan distance w.r.to currNode => edge cost
                int cost = abs(points[currNode][0] - points[i][0])
                         + abs(points[currNode][1] - points[i][1]);
                // update cost w.r.to currNode 
                if (!inMST[i] && minDist[i] > cost) {
                    minDist[i] = cost;
                }
            }
        }
        
        return result;
    }
}; 


// Kruskal
// Kruskal involves min heap to pick the smallest edge, and union-find to check if the edge is redundant.
//  We exit when all points are connected.
class SolutionKruskal {
public:
    int find(vector<int> &ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0;
        vector<int> ds(n, -1);
        vector<array<int, 3>> arr;
        for (auto i = 0; i < n; ++i)
            for (auto j = i + 1; j < n; ++j) {
                arr.push_back({abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i, j});
            }
        make_heap(begin(arr), end(arr), greater<array<int, 3>>()); // minHeap
        while (!arr.empty()) {
            pop_heap(begin(arr), end(arr), greater<array<int, 3>>());
            auto [dist, i, j] = arr.back();
            arr.pop_back();
            i = find(ds, i), j = find(ds, j);
            if (i != j) {
                res += dist;
                ds[i] += ds[j];
                ds[j] = i;
                if (ds[i] == -n)
                    break;
            }
        }
        return res;
    }
};

// Prim's
// In the Prim's algorithm, we are building a tree starting from some initial point. We track all connected points in visited. For the current point, we add its edges to the min heap. Then, we pick a smallest edge that connects to a point that is not visited. Repeat till all points are visited.
class SolutionPrim {
public:
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0, i = 0, connected = 0;
        vector<bool> visited(n);
        priority_queue<pair<int, int>> pq; // maxHeap: use -ve cost values to make it minHeap
        while (++connected < n) {
            visited[i] = true;
            for (int j = 0; j < n; ++j) // find relative distance of all neighbors w.r.to currNode
                if (!visited[j])
                    pq.push({-(abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1])), j});
            while (visited[pq.top().second]) // pop all visited nodes with min dist and pick min non-visited node
                pq.pop();
            res -= pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return res;
    }
};
int main(){
    
    return 0;
}