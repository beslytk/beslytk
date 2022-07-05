// /**
//  * @file BST_DFS.cpp
//  * 
//  * @author Besly Thomas (you@domain.com)
//  * @brief BST DFS pre, in and post order traversal
//  * @version 0.1
//  * @date 2022-06-25
//  * 
//  * @copyright Copyright (c) 2022
//  * 
//  */

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     struct Node* left;
//     struct Node* right;
// };


// Node* newNode(int data){

//     struct Node* temp = new Node;
//     temp->data = data;
//     temp->left = temp->right = nullptr;
//     return temp;
// }
// void printpreOrder(struct Node* head)
// {
//     if(head == nullptr) return;
//     printf("%d->", head->data);

//     printpreOrder(head->left);
//     printpreOrder(head->right);
// }

// void printInOrder(struct Node* head)
// {
//     if(head == nullptr) return;

//     printInOrder(head->left);
//     printf("%d->", head->data);
//     printInOrder(head->right);
// }

// void printpostOrder(struct Node* head)
// {
//     if(head == nullptr) return;

//     printpostOrder(head->left);
//     printpostOrder(head->right);
//     printf("%d->", head->data);
// }

// void printPreOrderIter(Node* head){
//     if(head == NULL)
//         return;

//     stack<Node*> stack;
//     stack.push(head);

//     while (!stack.empty())
//     {
//         Node* node = stack.top();
//         cout<< node->data << endl;
//         stack.pop();

//         if(node->right){

//             stack.push(node->right);
//         }
//         if(node->left){

//             stack.push(node->left);
//         }

//     }
        
// }

// void printInOrderIter(Node* head){
//     if(head == NULL)
//         return;

//     stack<Node*> stack;
//     Node* curr = head;
//     while (!stack.empty() || curr)
//     {

//         while (curr)
//         {
//             // goto extreme left leaf of tree and keep stacking each node along the way
//             stack.push(curr);
//             curr = curr->left;

//         }
//         curr = stack.top();
//         stack.pop();
//         cout<< curr->data << "->";
//         curr = curr->right;
//     }
        
// }

// int main(){

//     Node* head = newNode(1);

//     head->left = newNode(2);
//     head->right = newNode(3);
//     head->left->left = newNode(4);
//     head->left->right = newNode(5);
// 	/* Constructed binary tree is
// 		   1
// 		  / \
// 		 2	 3
// 		/ \
// 	   4   5
// 	*/
//     printf("\n preOrder traversal is:");
//     printpreOrder(head);
//     printf("\n InOrder traversal is:");
//     printInOrder(head);
//     printf("\n postOrder traversal is:");
//     printpostOrder(head);

//     // cout << "\nDFS traversal of binary tree is \n";
//     // printPreOrderIter(head);

//     cout << "\nDFS inOrder traversal of binary tree is \n";
//     printInOrderIter(head);

//     return 0;
// }