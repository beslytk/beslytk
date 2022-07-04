// /**
//  * @file topView.cpp
//  * @author your name (you@domain.com)
//  * @brief C++ program to print topview of binary tree
//  * @version 0.1
//  * @date 2022-06-29
//  * 
//  * @copyright Copyright (c) 2022
//  * Like vertical Order Traversal, we need to put nodes of same horizontal distance together. 
//  * We do a level order traversal so that the topmost node at a horizontal node is visited before 
//  * any other node of same horizontal distance below it. Hashing is used to check if a node at given 
//  * horizontal distance is seen or not. 
//  */

 
// #include <bits/stdc++.h>
// #include <iostream>
// #include <queue>
// #include <stack>
// using namespace std;
 
// // Structure of binary tree
// struct Node
// {
//     Node* left;
//     Node* right;
//     int hd;
//     int data;
// };
 
// // function to create a new node
// Node* newNode(int key)
// {
//     Node* node = new Node();
//     node -> left = node -> right = NULL;
//     node -> data = key;
//     return node;
// }

// void topView(Node* head){

//     if(head == nullptr) return;

//     map<int, int> m;
//     queue<pair<Node*, int> > q;
//     q.push(make_pair(head, 0));

//     while(!q.empty()){
//         pair<Node*, int> currPair = q.front();
//         Node* currNode = currPair.first;
//         int currHorizDist = currPair.second;
//         q.pop();
//         // count function returns 1 if the container contains an element whose key is equivalent
//         // to hd, or returns zero otherwise.
//         if(m.count(currHorizDist) == 0)
//             m[currHorizDist] = currNode->data;

//         if(currNode->left)
//             q.push(make_pair(currNode->left, currHorizDist - 1));

//         if(currNode->right)
//             q.push(make_pair(currNode->right, currHorizDist + 1));     
        

//     }

//     for (auto it = m.begin(); it != m.end(); it++) {
//         cout << it->second << " ";
//     }

// }

// // Driver Program to test above functions
// int main()
// {
//     Node* root = newNode(1);
//     root->left = newNode(2);
//     root->right = newNode(3);
//     root->left->right = newNode(4);
//     root->left->right->right = newNode(5);
//     root->left->right->right->right = newNode(6);
//     cout << "Following are nodes in top view of Binary "
//             "Tree\n";
//     topView(root);
//     return 0;
// }