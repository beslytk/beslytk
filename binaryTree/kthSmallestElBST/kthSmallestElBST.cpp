#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
/**
 * @brief https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * 
 * Strategy: Traverse bst in order and keep a coun-down counter to return the 
 *           kth element
 * 
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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        // inorder(root, k, result);
        inorder_iter(root, k, result);
        return result;
    }
private:
    void inorder(TreeNode* root, int& k, int& result) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, k, result);
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }

    void inorder_iter(TreeNode* node, int k, int& result){
        if(!node)
            return;
        stack<TreeNode*> stackDstInOrder;
        TreeNode* currNode = node;
        while (!stackDstInOrder.empty() || currNode)
        {
            while (currNode != NULL)
            {
                stackDstInOrder.push(currNode);
                currNode = currNode->left;
            }
            currNode = stackDstInOrder.top();
            stackDstInOrder.pop();
            k--;
            if(k==0){
                result = currNode->val;
                return;
            }
            currNode = currNode->right;
        }
               
    }
}; 

int main(){
    Solution sol;
    struct TreeNode *root = new TreeNode(3); 
    root->left = new TreeNode(1); 
    root->right = new TreeNode(4); 
    root->left->right = new TreeNode(2);
    cout<<"kth smallest in bst is? : "<< sol.kthSmallest(root, 2);
    return 0;
}