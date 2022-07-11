#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given head of linked list, reverse nodes of list k at a time
    Ex. head = [1,2,3,4,5], k = 2 -> [2,1,4,3,5]

    Maintain prev, curr, & temp pointers to reverse, count k times

    Time: O(n)
    Space: O(1)
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        ListNode* temp = NULL;
        
        int count = k;
        
        while (curr != NULL) {
            if (count > 1) {
                temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;// reverse link

                count--;
            } else {
                prev = curr; // now, the last element of the reversed group
                curr = curr->next; // now, first element of next group
                count = k; //  rewind group size
                
                ListNode* end = curr;
                // check if the remaining group size is at-least k
                // if less than k, return without reversing the rest
                for (int i = 0; i < k; i++) {
                    if (end == NULL) {
                        return dummy->next; 
                    }
                    end = end->next;
                }
            }
        }
        
        return dummy->next;
    }
}; 

int main(){
    
    return 0;
}