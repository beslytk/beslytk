/**
 * @file leftViewBST.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;


class Node{
 public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        this->left = this->right = nullptr;
    }
};

Node *newNode(int item)
{
	Node *temp = ( Node *)malloc(sizeof( Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void rightViewUtil(Node* root, int currLevelDepth, int* levelMax, vector<int>& retVec){

    if(root == nullptr) return;
    // only one element in a level will satisfy below condition
    // same levelMax is passed on to revcursive calls to left and right for each depth
    if(*levelMax < currLevelDepth){
        retVec.push_back(root->data);
        *levelMax = currLevelDepth; // updated for first valid node in a level
    }
    // only change bwtween right view and left view
    rightViewUtil(root->right, (currLevelDepth +1), levelMax, retVec);
    rightViewUtil(root->left , (currLevelDepth +1), levelMax, retVec);

}

//Function to return a list containing elements of left view of the binary tree.
vector<int> rightView(Node *root)
{
   vector<int> ret;
   int levelMax = 0;
   rightViewUtil(root, 1, &levelMax, ret);
   return ret;
}

// function to print Right view of
// binary tree
void printRightViewIter(Node* root)
{
    if (root == NULL)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        // get number of nodes for each level
        int n = q.size();
 
        // traverse all the nodes of the current level
        while (n--) {
 
            Node* x = q.front();
            q.pop();
 
            // print the last node of each level
            if (n == 0) {
                cout << x->data << " ";
            }
            // if left child is not null push it into the
            // queue
            if (x->left)
                q.push(x->left);
            // if right child is not null push it into the
            // queue
            if (x->right)
                q.push(x->right);
        }
    }
}

int main()
{
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    /* Constructed binary tree is
             10
            /   \
           2     3
          / \   / \
         7   8 12  15
                   /
                  14
    */
    vector<int> retVec =  rightView(root);
    for(int i=0; i < retVec.size(); i++){
        cout << retVec[i] << endl;
    }

    printRightViewIter(root);
    return 0;
}