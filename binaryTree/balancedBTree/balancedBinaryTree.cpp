#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given binary tree, determine if height-balanced (all left & right subtrees height diff <= 1)

    Check if subtrees are balanced, if so, use their heights to determine further balance

    Time: O(n)
    Space: O(n)
    https://leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }
private:
    bool dfs(TreeNode* root, int& height) {
        if (root == NULL) {
            height = -1;
            return true;
        }
        
        int left = 0;
        int right = 0;
        
        if (!dfs(root->left, left) || !dfs(root->right, right)) {
            return false;
        }
        if (abs(left - right) > 1) {
            return false;
        }
        // height for current node
        height = 1 + max(left, right);
        return true;
    }

}; 

int main(){
    Solution sol;
    struct TreeNode *root = new TreeNode(3); 
    root->left = new TreeNode(9); 
    root->right = new TreeNode(20); 
    root->right->left = new TreeNode(15); 
    root->right->right = new TreeNode(7);
    cout<<"Is the given tree balanced? : "<< sol.isBalanced(root);

    struct TreeNode *root2 = new TreeNode(1); 
    root2->left = new TreeNode(2); 
    root2->right = new TreeNode(2); 
    root2->left->left = new TreeNode(3); 
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4); 
    root2->left->left->right = new TreeNode(4); 
    cout<<"Is the given tree balanced? : "<< sol.isBalanced(root2);
    return 0;
}