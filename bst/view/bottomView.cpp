// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
  
// Tree node class
struct Node
{
    int data; //data of the node
    int hd; //horizontal distance of the node
    Node *left, *right; //left and right references
  
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};


void bottomView(Node* head){

    if(head == nullptr) return;

    queue<pair<int, Node*> > q;

    map<int, int > m;
    int hd = 0;
    q.push(make_pair(hd, head));

    while(!q.empty()){

        pair<int, Node*> currPair = q.front();

        q.pop();

        m[currPair.first] = currPair.second->data;

        if(currPair.second->left){
            q.push(make_pair(currPair.first - 1, currPair.second->left));
        }

        if(currPair.second->right){
            q.push(make_pair(currPair.first + 1, currPair.second->right));
        }
    }

    for(auto it = m.begin(); it != m.end(); it++ ){
        cout<< it->second << endl;
    }

}

// Driver Code
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}