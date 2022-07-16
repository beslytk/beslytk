#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

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

	bool isValidBST(TreeNode* root) {
		return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
	}
private:
	bool isValidBSTHelper(TreeNode* root, long min, long max) {
		if(root == NULL){
			return true;
		}   
		if(root->val > min && root->val < max) {
            //left subtree should be bounded by its parent node as max and min of parent
            //right subtree should be bounded by its parent node as min and max of parent
			return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
		}    
		return false;
	}     
};
// Inorder traversal is apt to validate since it traverses
// a binsary search tree in increasing order
class Solution_Iter {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* prev = NULL;
        
        while (!stk.empty() || root != NULL) {
            while (root != NULL) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            
            if (prev != NULL && prev->val >= root->val) {
                return false;
            }
            // reassign prev to compare with next node in in-order traversal
            prev = root;
            root = root->right;
        }
        
        return true;
    }
};

int main(){
    
    return 0;
}