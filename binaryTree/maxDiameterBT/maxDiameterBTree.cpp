#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given root of binary tree, return length of diameter of tree (longest path b/w any 2 nodes)
    Max path b/w 2 leaf nodes, "1 +" to add path
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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result; // max Diameter
    }
private:
    int dfs(TreeNode* root, int& result) {
        if (root == NULL) {
            return 0;
        }
        
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        // update result if the diameter(sum of left,right height)
        // is greater than result
        result = max(result, left + right);
        return 1 + max(left, right); // height of current node
    }
}; 

int main(){
    Solution sol;
    struct TreeNode *root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5);
    cout<<"max diameter of the tree is: "<<sol.diameterOfBinaryTree(root);
    return 0;
}