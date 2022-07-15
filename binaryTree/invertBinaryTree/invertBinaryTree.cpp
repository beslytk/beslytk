#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given the root of a binary tree, invert the tree, and return its root
    Ex. root = [4,2,7,1,3,6,9] -> [4,7,2,9,6,3,1], [2,1,3] -> [2,3,1]

    Preorder traversal, at each node, swap it's left and right children

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
// Recursive:
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
}; 

// Use stack as usual in all tree iterative solutions
class Solution_Iter {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            if (!curr) continue;
            s.push(curr->left);
            s.push(curr->right);
            swap(curr->left, curr->right);
        }
        return root;
    }
};

/* Helper function to print levelOrder traversal.*/
void printLevelOrder(TreeNode* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<TreeNode*> q;
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        TreeNode* node = q.front();
        cout << node->val << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
    cout<<endl;
}

int main(){
    Solution sol;
    struct TreeNode *root = new TreeNode(4); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(7); 
    root->left->left = new TreeNode(1); 
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6); 
    root->right->right = new TreeNode(9);
    printLevelOrder(root);
    TreeNode* invRoot = sol.invertTree(root);
    printLevelOrder(invRoot);
    return 0;
}