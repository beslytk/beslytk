#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
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
        // first point added without any cost
        minDist[0] = 0;
        
        int result = 0;
        
        while (edgesUsed < n) {
            int currMinEdge = INT_MAX;
            int currNode = -1;
            
            // greedily pick lowest cost node not in MST
            // first iteration 0th node meets criteria
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && currMinEdge > minDist[i]) {
                    currMinEdge = minDist[i];
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

int main(){
    
    return 0;
}