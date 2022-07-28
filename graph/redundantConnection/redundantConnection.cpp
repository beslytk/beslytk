#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given undirected graph, return an edge that can be removed to make a tree
    Ex. edges = [[1,2],[1,3],[2,3]] -> [2,3]

    If n nodes & n edges, guaranteed a cycle
    How to know creating cycle? When connecting a node already connected
    Union-Find: can find this redundant edge, track parents & ranks

    Time: O(n)
    Space: O(n)
    https://leetcode.com/problems/redundant-connection/
*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> parents;
        vector<int> ranks; // number of nodes as children
        for (int i = 0; i < n + 1; i++) {
            parents.push_back(i); // initially all nodes are its own parent
            ranks.push_back(1);  // all nodes are rank 1 (not yet connected to other)
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            // if same parent, return false as this 
            // connection results in cycle
            if (!doUnion(parents, ranks, n1, n2)) {
                result = {n1, n2};
                break;
            }
        }
        return result;
    }
private:
    int doFind(vector<int>& parents, int n) {
        int p = parents[n];
        while (p != parents[p]) {
            // shorten the lengths as we go up the chain of parents
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }
    
    bool doUnion(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
        int p1 = doFind(parents, n1);
        int p2 = doFind(parents, n2);
        if (p1 == p2) {
            return false;
        }
        // node with most rank should be the parent
        if (ranks[p1] > ranks[p2]) {
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        } else {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }
        
        return true;
    }
};
// [[1,2],[1,3]] 
//     1
//   /   \
//  2     3
// [[1,2],[1,3],[2,3]]
// Union(2,3) => same parent i.e. 1. so this edge would make graph a cycle 
int main(){
    
    return 0;
}