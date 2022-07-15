#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given a binary search tree (BST), find the LCA of 2 given nodes in the BST

    Use BST property: if curr > left & right go left, else if < go right, else done

    Time: O(n)
    Space: O(n)
*/

/*** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            // either root is where split happens (p on left, q on right)
            // or p||q equals to root. Either case is the lowest ancestor
            return root;
        }
    }
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         while (root != NULL) {
//             if (p->val < root->val && q->val < root->val) {
//                 root = root->left;
//             } else if (p->val > root->val && q->val > root->val) {
//                 root = root->right;
//             } else {
//                 return root;
//             }
//         }
//         return NULL;
//     }
// }; 

int main(){
    
    return 0;
}