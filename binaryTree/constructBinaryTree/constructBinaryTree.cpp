#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/**
 * @brief https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

    Given 2 integer arrays preorder & inorder, construct & return the binary tree
    Ex. preorder = [3,9,20,15,7], inorder = [9,3,15,20,7] -> [3,9,20,null,null,15,7]

    Inorder Traversal -> LEFT -> ROOT ->RIGHT
    PreOrder Traversal -> ROOT -> LEFT -> RIGHT

    We have two observations :
    The first element in 'preorder' is the root of the tree. Let it be x
    Elements left to x in 'inorder' form the LEFT subtree.
    Elements right to x in 'inorder' forms the RIGHT subtree.

    Preorder dictates nodes, inorder dictates subtrees (preorder values, inorder positions)
    Time: O(n)
    Space: O(n)
*/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int start, int end) {
        // base case: implies we are at a NULL node
        if (start > end) {
            return NULL;
        }
        // subtree root node is obtainded from preorder at 'index'
        // construct each node in sequence of preOrder array
        TreeNode* root = new TreeNode(preorder[index]);
        // find where to split inorder array into left and right subtree
        int split = 0;
        for (int i = start; i <= end; i++) {
            if (preorder[index] == inorder[i]) {
                split = i;
                break;
            }
        }

        index++;
        
        root->left  = build(preorder, inorder, index, start, split - 1);
        root->right = build(preorder, inorder, index, split + 1, end);
        
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
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder  = {9,3,15,20,7};
    TreeNode* tree = sol.buildTree(preorder, inorder);
    printLevelOrder(tree);

    vector<int> preorder2 = {1,2,4,5,3};
    vector<int> inorder2  = {4,2,5,1,3};
    TreeNode* tree2 = sol.buildTree(preorder2, inorder2);
    printLevelOrder(tree2); // 1 2 3 4 5 
    /* Constructed binary tree is
		   1
		  / \
		 2	 3
		/ \
	   4   5
	*/
    vector<int> preorder3 = {-1};
    vector<int> inorder3  = {-1};
    TreeNode* tree3 = sol.buildTree(preorder3, inorder3);
    printLevelOrder(tree3); // -1

    return 0;
}