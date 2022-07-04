// #include <stdio.h>
// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// class Node{
// public:
//     int data;
//     Node* left, *right;
//     Node(){

//     }
//     Node(int val){
//         data = val;
//         left=right=nullptr;
//     }

// };

// Node* newNode(int val){
//     Node* temp = new Node;
//     temp->data = val;
//     temp->left=nullptr;
//     temp->right=nullptr;
//     return temp;
// }

// void findMinMax(Node* root, int& min, int& max, int horizDist){
//     if(root == nullptr)
//         return;
//     if(horizDist<min)
//         min = horizDist;
//     else if(horizDist > max)
//         max = horizDist;    
//     findMinMax(root->left, min, max, horizDist - 1);
//     findMinMax(root->right, min, max, horizDist + 1);

// }

// void printCurrVertLine(Node* root, int& lineNo, int horizDist){
//     if(root == nullptr)
//         return;
//     if(horizDist == lineNo)
//         cout << root->data << "->";
   
//     printCurrVertLine(root->left, lineNo, horizDist - 1);
//     printCurrVertLine(root->right, lineNo, horizDist + 1);

// }

// void verticalOrder(Node* root){
    
//     int min = 0, max= 0;
//     findMinMax(root, min, max, 0);

//     for(int lineNo = min ; lineNo<=max; lineNo++){
//         printCurrVertLine(root, lineNo, 0);
//         cout<<endl;
//     }
// }

// int main(){

//     // Create binary tree shown in above figure
//     Node *root = newNode(1);
//     root->left = newNode(2);
//     root->right = newNode(3);
//     root->left->left = newNode(4);
//     root->left->right = newNode(5);
//     root->right->left = newNode(6);
//     root->right->right = newNode(7);
//     root->right->left->right = newNode(8);
//     root->right->right->right = newNode(9);
  
//     cout << "Vertical order traversal is: \n";
//     verticalOrder(root);
//     return 0;
// }
