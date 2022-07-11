#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/** Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    Given head of a linked list, determine if it has a cycle in it

    Slow/fast pointers, if they ever intersect then there's a cycle

    Time: O(n)
    Space: O(1)
    Strategy: Floyd's Tortoise and Hare
              use slow and fast pointer. If the fast and slow
              pointers meet while traversing, there is a cycle 
*/

class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> m;
        ListNode* curr = head;
        while (curr)
        {
            if(m.find(curr) != m.end()){
                return true;
            }
            m[curr] = true;
            curr = curr->next;
        }
        return false;    
    }

}; 

int main(){
    Solution1 sol;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    cout<<"given LL has cycle? : "<< sol.hasCycle(head);
    return 0;
}