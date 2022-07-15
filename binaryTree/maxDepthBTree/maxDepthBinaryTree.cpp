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

//Recursive Soln
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
        
    }
};
// Iterative BFS /Level Order
class Solution_BFS_Iter {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        queue<TreeNode*> bfsQue;
        int height = 0;

        bfsQue.push(root);
        while (!bfsQue.empty())
        {
            //snapshot of current que length
            int queLength = bfsQue.size();
            // iterate over the queLength (nodes in a single Level)
            // and then increment the height
            for (size_t i = 0; i < queLength; i++)
            {
                TreeNode* node = bfsQue.front();
                bfsQue.pop();

                if(node->left){
                    bfsQue.push(node->left);
                }
                if(node->right){
                    bfsQue.push(node->right);
                }
            }
            height += 1;

        }
        return height;
    }
};

class Solution_DFS_Iter {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        // stackElement = {Node*, currHeight}
        stack<pair<TreeNode*, int> > dfsStack;
        dfsStack.push({root, 1});
        int height = 0;

        while (!dfsStack.empty())
        {
            auto currElem = dfsStack.top();
            dfsStack.pop();
            if( currElem.first){
                height = max(height, currElem.second);
                dfsStack.push({currElem.first->left, currElem.second + 1});
                dfsStack.push({currElem.first->right, currElem.second + 1});
            }
        }
        return height;

    }
};

int main(){
    Solution sol;
    struct TreeNode *root = new TreeNode(4); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(7); 
    root->left->left = new TreeNode(1); 
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6); 
    root->right->right = new TreeNode(9);
    cout<< "(recursion) max depth of tree is: "<<sol.maxDepth(root)<<endl;

    Solution_BFS_Iter sol_bfs;
    cout<< "(bfs) max depth of tree is: "<<sol_bfs.maxDepth(root)<<endl;

    Solution_DFS_Iter sol_dfs;
    cout<< "(dfs preorder) max depth of tree is: "<<sol_dfs.maxDepth(root)<<endl;
    return 0;
}