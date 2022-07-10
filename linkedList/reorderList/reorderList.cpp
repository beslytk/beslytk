#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given head of linked-list, reorder list alternating outside in
    Ex. head = [1,2,3,4] -> [1,4,2,3], head = [1,2,3,4,5] -> [1,5,2,4,3]
    Find middle node, split in half, reverse 2nd half of list, merge
    Time: O(n)
    Space: O(1)
*/

/** Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head->next == NULL) {
            return;
        }
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // to handle cases of odd and even number of nodes in LL
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;       // one step
            fast = fast->next->next; // take leap of 2 nodes
        }
        
        prev->next = NULL;
        
        ListNode* l1 = head;
        // slow points to start of 2nd half of LL
        // reverse the 2nd half
        ListNode* l2 = reverse(slow);
        
        merge(l1, l2);
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    // merge two given linked list
    void merge(ListNode* l1, ListNode* l2) {
        while (l1 != NULL) {
            // save the ptr to next nodes, since the links will be changed
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;
            // reordering as required
            l1->next = l2;
            if (p1 == NULL) {
                break;
            }
            l2->next = p1;
            // reassign current ptrs to next nodes
            l1 = p1;
            l2 = p2;
        }
    }
}; 

int main(){
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    sol.reorderList(head);
    ListNode* curr = head;
    while (curr)
    {
        cout<< curr->val<<"->";
        curr = curr->next;
    }
    cout<< "NULL";
    return 0;
}