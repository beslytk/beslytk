#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected 

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int ans = 0;

    void constrGraph(TreeNode* root,  vector<int> graph[], int parent ){
        if(!root) return;

        if (parent!=-1){    // skipped first time
            graph[parent].push_back(root->val);
            graph[root->val].push_back(parent);
        }

        constrGraph(root->left, graph, root->val); // graph connect child with parent node
        constrGraph(root->right, graph, root->val); // vice-versa
        return;
    }

    void dfs(vector<int> graph[], int curr, int parent, int depth[]){
        if (parent!= -1) depth[curr] = depth[parent] + 1;
        ans = max(ans, depth[curr]);
        for (auto &&n : graph[curr])
        {
            if(n!=parent)
                dfs(graph, n, curr, depth);
        }

    }
    
    int amountOfTime(TreeNode* root, int start) {
        int N = 1e5 + 1;
        vector<int> graph[N];
        constrGraph(root, graph, -1);
        int depth[N]; memset(depth, 0 ,sizeof(depth));
        dfs(graph, start, -1, depth);
        return ans;
    }
};

int main(){
    
    return 0;
}