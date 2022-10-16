#include <bits/stdc++.h>
using namespace std;

/*  Dijkstra's Algo

    Signal sent from node k to network of n nodes, return time for all nodes to receive it
    Ex. times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2 -> 2
                  u,v,w -> u = source node, v = target node, w = signal travel time

    Shortest path from node k to every other node, Dijkstra's to find fastest path

    Time: O(V + E log V)
    Space: O(V + E)
    https://leetcode.com/problems/network-delay-time/
*/

//------------------------
//         4
//    '1'---->'2'
//    1|       ^ 1
//     v       |
//    '3'---->'4'
//         1  
//------------------------
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // array of vector-of-pairs
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int dest   = times[i][1];
            int time   = times[i][2];
            // outgoing nodes with time from source node
            adj[source].push_back({time, dest});
        }
        // all init with INT_MAX => equivalent to visit Set
        vector<int> signalReceiveTime(n + 1, INT_MAX);
        // minHeap of pair-> (time, node) i.e time to reach node from source
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        // source (k) node require 0 time to arrive at node
        pq.push({0, k});
        
        // time for start node is 0
        signalReceiveTime[k] = 0;
        // BFS layer by layer traversal
        while (!pq.empty()) {
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            // the expensive route to rach the node (handled last in minHeap)
            if (currNodeTime > signalReceiveTime[currNode]) {
                continue;
            }
            
            // send signal to adjacent nodes
            for (int i = 0; i < adj[currNode].size(); i++) {
                pair<int, int> edge = adj[currNode][i]; // ith neighbor
                int edgetime = edge.first;
                int neighborNode = edge.second;
                
                // fastest signal time for neighborNode so far
                if (signalReceiveTime[neighborNode] > currNodeTime + edgetime) {
                    signalReceiveTime[neighborNode] = currNodeTime + edgetime;
                    pq.push({signalReceiveTime[neighborNode], neighborNode});
                }
            }
        }
        
        int result = INT_MIN;
        for (int i = 1; i <= n; i++) {
            // get the most time required to send signal to a node
            result = max(result, signalReceiveTime[i]);
        }
        // if certain nodes couldnt receive signal
        if (result == INT_MAX) {
            return -1;
        }
        return result;
    }
};

typedef pair<int, int> pii;

class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii> > g(n + 1);
        for (const auto& t : times) {
            g[t[0]].emplace_back(t[1], t[2]);
        }
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
		vector<bool> vis(n + 1, false);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq; // minHeap
        pq.emplace(0, k);
        int u, v, w;
        while (!pq.empty()) {
            u = pq.top().second; pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
};

int main(){
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    Solution sol;
    cout<< "max required time to reach all nodes is: "<<sol.networkDelayTime(times, n, k)<<endl;;

    return 0;
}

// Algorithm 
// 1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in the shortest-path tree, i.e.,
//    whose minimum distance from the source is calculated and finalized. Initially, this set is empty. 
// 2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. 
//    Assign distance value as 0 for the source vertex so that it is picked first. 
// 3) While sptSet doesn’t include all vertices 
// ….a) Pick a vertex 'u' which is not there in sptSet and has a minimum distance value. 
// ….b) Include 'u' to sptSet. 
// ….c)Update distance value of all 'adjacent vertices of u'. To update the distance values, 
//     iterate through all adjacent vertices. For every adjacent vertex v,
//     if the sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v,
//     then update the distance value of v. 