/**
 * @file bst_bfs_traversal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
};


void printLevelOrder(Node* head){

    if(head == NULL)
        return;

    queue<Node*> que;

    que.push(head);

    while (!que.empty())
    {
        Node* node = que.front();
        cout<< node->data << endl;
        que.pop();

        if(node->left){

            que.push(node->left);
        }

        if(node->right){

            que.push(node->right);
        }
    }
        
}

int height(Node* node){
    if(node == NULL) 
        return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if(leftHeight > rightHeight){
        return (1 + leftHeight);
    }else {
        return (1 + rightHeight);
    }

}

void printCurrentLevel(Node* node, int level){

    if(node == NULL) return;

    if(level == 1){
        cout<< node->data << "->";
    }
    else{
        printCurrentLevel(node->left, level-1);
        printCurrentLevel(node->right, level-1);
    }
}

void printLevelOrderRecursive(Node* node){
    
    int levels = height(node);
    for(int i=1; i <= levels; i++){
        printCurrentLevel(node, i);
    }
}

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    // Let us create binary tree shown in above diagram
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    /* Constructed binary tree is
           1
          / \
         2	 3
        / \
       4   5
    */
    cout << "\nLevel Order traversal of binary tree is \n";
    printLevelOrder(root);
    
    cout << "\nRecursive Level Order traversal of binary tree is \n";
    printLevelOrderRecursive(root);
    
    return 0;
}
