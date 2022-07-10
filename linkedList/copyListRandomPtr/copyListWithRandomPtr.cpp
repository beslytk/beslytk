#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given linked list w/ also a random pointer, construct deep copy

    Hash map {old -> new}, O(n) space
    Optimize interweave old and new nodes, O(1) space
    A -> A' -> B -> B' -> C -> C', A'.random = A.random.next

    Time: O(n)
    Space: O(n) -> can optimize to O(1)
    Solution1:
    Strategy: maintain a hashmap from old node to new.
              a function to generate clone given old node as input
              & keep all the newly cloned node in hashmap
              & return the node from hashmap if already present on next request to clone
    Solution2:
    Strategy: 1>make clone taking value from old
                clone->next point to old_ptr->next 
                make the old_ptr->next point to new clone.
              2>Loop on old_ptr and assign current clone->random
                as clone corresponding to old_ptr random
              3> correctly assign clone->next
              in a loop set old_ptr->next to as in original LL
              then assign clone->next to corresponding clone
              (rest old LL nodes are still pointing to corresponding clone) 
    https://leetcode.com/problems/copy-list-with-random-pointer/
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* oldNode = head;
        Node* newNode = new Node(oldNode->val);
        // key=oldNode & value = newNode
        visited[oldNode] = newNode;
        while (oldNode != NULL) {
            newNode->next = getClonedNode(oldNode->next);
            newNode->random = getClonedNode(oldNode->random);
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return visited[head];
    }
private:
    // map old to new node
    unordered_map<Node*, Node*> visited;
    // make a clone and add to map linking old with new
    Node* getClonedNode(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        // lookup in map if the node was already added while cloning from random
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        visited[node] = new Node(node->val);
        return visited[node];
    }
};

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        
        Node* ptr = head;
        // make all clone nodes filled with values
        while (ptr != NULL) {
            Node* newNode = new Node(ptr->val);
            // new clones next points to olds next
            newNode->next = ptr->next;
            // point old to new Node
            ptr->next = newNode;
            // move ahead in old list
            ptr = newNode->next;
        }
        ptr = head;

        //assign clone->random
        while (ptr != NULL) {
            if (ptr->random == NULL) {
                // (ptr->next) now points to its (new clone)
                ptr->next->random == NULL;
            } else {
                // clones random points to (ptr->random = random of old node)->next 
                // i.e clone corresponding to current ptr's random
                ptr->next->random = ptr->random->next;
            }
            // move to next node from old list
            ptr = ptr->next->next;
        }
        
        Node* oldPtr = head;
        Node* newPtr = head->next; // head of new Linked list
        Node* oldHead = head->next;
        // assign clone->next
        while (oldPtr != NULL) {
            // reassign original way of old LL pointers to next nodes
            oldPtr->next = oldPtr->next->next;
            if (newPtr->next == NULL) {
                newPtr->next = NULL;
            } else {
                // now (newPtr->next->next) is the corresponding node from clone list
                newPtr->next = newPtr->next->next;
            }
            // traverse along the LL
            oldPtr = oldPtr->next;
            newPtr = newPtr->next;
        }
        
        return oldHead;
    }
}; 

int main(){
    Solution1 sol;
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    Node* currOld = head;
    while (currOld)
    {
        cout<<currOld->val<<"|"<< currOld<<"-> ";
        currOld = currOld->next;
    }
    cout<< "NULL"<<endl;
    //Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    //Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* clonedLL = sol.copyRandomList(head);
    Node* curr = clonedLL;
    while (curr)
    {
        cout<< curr->val<<"|"<<curr<<"-> ";
        curr = curr->next;
    }
    cout<< "NULL";
    return 0;
    return 0;
}