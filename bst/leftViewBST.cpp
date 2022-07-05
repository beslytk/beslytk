// /**
//  * @file leftViewBST.cpp
//  * @author your name (you@domain.com)
//  * @brief 
//  * @version 0.1
//  * @date 2022-06-26
//  * 
//  * @copyright Copyright (c) 2022
//  * 
//  */
// #include <stdio.h>
// #include<bits/stdc++.h>
// using namespace std;


// class Node{
//  public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val){
//         this->data = val;
//         this->left = this->right = nullptr;
//     }
// };

// Node *newNode(int item)
// {
// 	Node *temp = ( Node *)malloc(sizeof( Node));
// 	temp->data = item;
// 	temp->left = temp->right = NULL;
// 	return temp;
// }

// void leftViewUtil(Node* root, int currLevelDepth, int* levelMax, vector<int>& retVec){

//     if(root == nullptr) return;
//     // only one element in a level will satisfy below condition
//     // same levelMax is passed on to revcursive calls to left and right for each depth
//     if(*levelMax < currLevelDepth){
//         retVec.push_back(root->data);
//         *levelMax = currLevelDepth; // updated for first valid node in a level
//     }
//         leftViewUtil(root->left , (currLevelDepth +1), levelMax, retVec);
//         leftViewUtil(root->right, (currLevelDepth +1), levelMax, retVec);

// }

// //Function to return a list containing elements of left view of the binary tree.
// vector<int> leftView(Node *root)
// {
//    vector<int> ret;
//    int levelMax = 0;
//    leftViewUtil(root, 1, &levelMax, ret);
//    return ret;
// }

// // function to print left view of
// // binary tree
// void printLeftViewIter(Node* root)
// {
//     if (!root)
//         return;
 
//     queue<Node*> q;
//     q.push(root);
 
//     while (!q.empty())
//     {    
//         // number of nodes at current level
//         int n = q.size();
         
//         // Traverse all nodes of current level
//         for(int i = 1; i <= n; i++)
//         {
//             Node* temp = q.front();
//             q.pop();
                 
//             // Print the left most element at the level
//             if (i == 1)
//                 cout<<temp->data<<" ";
             
//             // Add left node to queue
//             if (temp->left != NULL)
//                 q.push(temp->left);
 
//             // Add right node to queue
//             if (temp->right != NULL)
//                 q.push(temp->right);
//         }
//     }
// }  

// int main()
// {
//     Node* root = newNode(10);
//     root->left = newNode(2);
//     root->right = newNode(3);
//     root->left->left = newNode(7);
//     root->left->right = newNode(8);
//     root->right->right = newNode(15);
//     root->right->left = newNode(12);
//     root->right->right->left = newNode(14);
//     /* Constructed binary tree is
//              10
//             /   \
//            2     3
//           / \   / \
//          7   8 12  15
//                    /
//                   14
//     */
//     vector<int> retVec =  leftView(root);
//     for(int i=0; i < retVec.size(); i++){
//         cout << retVec[i] << endl;
//     }

//     printLeftViewIter(root);
//     return 0;
// }