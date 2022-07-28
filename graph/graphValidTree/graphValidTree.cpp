#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Graph of nodes, list of edges, determine if edges make valid tree
    Ex. n = 5, edges = [[0,1],[0,2],[0,3],[1,4]] -> true

    (1) For graph to be a valid tree, must have exactly n - 1 edges
    (2) If graph fully connected & has n - 1 edges, can't contain cycle

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            // Undirected Graph, so each vertex of edge
            // has adjacency to the other node
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n); // all set false initially
        // check if graph has cycle
        if (hasCycle(adj, visited, -1, 0)) {
            return false;
        }
        // check if all nodes are connected
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
private:
    bool hasCycle(vector<vector<int>>& adj, vector<bool>& visited, int parent, int current) {
        if (visited[current]) {
            return true;
        }
        // mark as visited
        visited[current] = true;
        // checking for cycles and connectedness
        for (int i = 0; i < adj[current].size(); i++) {
            int neigh = adj[current][i];
            // possible that parent is in adjacency list. Skip as already processed
            // dfs to adjacent nodes
            if (neigh != parent && hasCycle(adj, visited, current, neigh)) {
                return true;
            }
        }
        return false;
    }
}; 

int main(){
    
    return 0;
}