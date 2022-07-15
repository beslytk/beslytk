#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given the roots of 2 binary trees, return true if a tree has a subtree of the other tree

    Check at each node of the root tree if it's the same as the subRoot tree (structure + values)

    Time: O(m x n)
    Space: O(m)
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return false;
        }
        if (isSame(root, subRoot)) {
            return true;
        }
        //recursively go to left and right subtree and check if they are same as subRoot
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) {
            return true;
        }
        if (root == NULL || subRoot == NULL) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        // if current nodes are same, recursively check left and right subtree of both
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
}; 

int main(){
    
    return 0;
}