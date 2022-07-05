// /**
//  * @file verticalPrint_hashMap.cpp
//  * @author your name (you@domain.com)
//  * @brief 
//  * @version 0.1
//  * @date 2022-06-29
//  * 
//  * @copyright Copyright (c) 2022
//  * We can do preorder traversal of the given Binary Tree. While traversing the tree, we can recursively calculate HDs.
//  * We initially pass the horizontal distance as 0 for root. For left subtree, we pass the Horizontal Distance as Horizontal 
//  * distance of root minus 1. For right subtree, we pass the Horizontal Distance as Horizontal Distance of root plus 1. 
//  * For every HD value, we maintain a list of nodes in a hash map.
//  * Whenever we see a node in traversal, we go to the hash map entry and add the node to the hash map using HD as a key in a map.
//  * 
//  */

// // C++ program for printing vertical order of a given binary tree
// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;

// // Structure for a binary tree node
// struct Node
// {
// 	int key;
// 	Node *left, *right;
// };

// // A utility function to create a new node
// struct Node* newNode(int key)
// {
// 	struct Node* node = new Node;
// 	node->key = key;
// 	node->left = node->right = NULL;
// 	return node;
// }

// // Utility function to store vertical order in map 'm'
// // 'hd' is horizontal distance of current node from root.
// // 'hd' is initially passed as 0
// void getVerticalOrder(Node* root, int hd, map<int, vector<int>> &m)
// {
// 	// Base case
// 	if (root == NULL)
// 		return;

// 	// Store current node in map 'm'
// 	m[hd].push_back(root->key);

// 	// Store nodes in left subtree
// 	getVerticalOrder(root->left, hd-1, m);

// 	// Store nodes in right subtree
// 	getVerticalOrder(root->right, hd+1, m);
// }

// // The main function to print vertical order of a binary tree
// // with the given root
// void printVerticalOrder(Node* root)
// {
// 	// Create a map and store vertical order in map using
// 	// function getVerticalOrder()
// 	map < int,vector<int> > m;
// 	int hd = 0;
// 	getVerticalOrder(root, hd,m);

// 	// Traverse the map and print nodes at every horizontal
// 	// distance (hd)
// 	map< int,vector<int> > :: iterator it;
// 	for (it=m.begin(); it!=m.end(); it++)
// 	{
// 		for (int i=0; i<it->second.size(); ++i)
// 			cout << it->second[i] << " ";
// 		cout << endl;
// 	}
// }

// // Driver program to test above functions
// int main()
// {
// 	Node *root = newNode(1);
// 	root->left = newNode(2);
// 	root->right = newNode(3);
// 	root->left->left = newNode(4);
// 	root->left->right = newNode(5);
// 	root->right->left = newNode(6);
// 	root->right->right = newNode(7);
// 	root->right->left->right = newNode(8);
// 	root->right->right->right = newNode(9);
// 	cout << "Vertical order traversal is: \n";
// 	printVerticalOrder(root);
// 	return 0;
// }
