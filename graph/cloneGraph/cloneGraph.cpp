#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given ref of a node in connected undirected graph, return deep copy

    Both BFS & DFS work, map original node to its copy

    Time: O(m + n)
    Space: O(n)
    https://leetcode.com/problems/clone-graph/
*/

/**/
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution_DFS {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        // if clone not present in map, create clone
        // and dfs recursively for each neighbor to add clones neighbors 
        if (m.find(node) == m.end()) {
            m[node] = new Node(node->val);
            for (int i = 0; i < node->neighbors.size(); i++) {
                Node* neighbor = node->neighbors[i];
                m[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return m[node];
    }
private:
    unordered_map<Node*, Node*> m; // map old nodes to new clones
};

// bfs solution
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        
        Node* copy = new Node(node->val);
        m[node] = copy; // add node,clone to map
        
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (int i = 0; i < curr->neighbors.size(); i++) {
                Node* neighbor = curr->neighbors[i];
                // push to queue if not already cloned & processed for neighbors
                if (m.find(neighbor) == m.end()) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }
        
        return copy;
    }
private:
    unordered_map<Node*, Node*> m;
}; 

int main(){
    
    return 0;
}