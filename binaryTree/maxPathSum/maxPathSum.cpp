#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given root of binary tree, return max path sum (seq of adj node values added together)
    Path can only have <= 1 split point, assume curPath has it, so return can't split again
    Time: O(n)
    Space: O(n)
    https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
private:
    int dfs(TreeNode* root, int& maxPath) {
        if (root == NULL) {
            return 0;
        }
        // post order traversal,as both left,right subtrees path-sum need to be used
        int left = max(dfs(root->left, maxPath), 0); // max with 0 to ignore any -ve children
        int right = max(dfs(root->right, maxPath), 0);
        
        // path-sum considering split at current node if this is considered, parent node cant be taken
        int curPath = root->val + left + right; // do split at curr node and ignore its parent 
        maxPath = max(maxPath, curPath);
        
        // return path-sum without split, since the parent of current node could have split
        return root->val + max(left, right); // return to parent node, what we can obtain w/o split
    }
}; 

int main(){
    
    return 0;
}