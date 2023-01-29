#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007



struct Node
{
	int val;
	Node *left, *right;
};

// A utility function to create a new node
struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->val = key;
	node->left = node->right = NULL;
	return node;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// vetical print
// use a hashmap<int, vector<int>> // horix dist, elements
// global hashMap
map<int, vector<int> > m;
void getVerticalLines(Node* head, int hd){
    if(!head)
        return;
    
    m[hd].push_back(head->val);
    getVerticalLines(head->left, hd-1);
    getVerticalLines(head->right, hd+1);
    return;
}

void printVerticalView(Node* head){
    if(!head)
        return;
    getVerticalLines(head, 0);
    
    for(auto it = m.begin();it!=m.end(); it++){
        for(auto& el:it->second){
            cout<<el<<"->";
        }
        cout<<endl;    
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vetical print
// find the min and max horiz distances
// find nodes in same horiz dist and group them into a vector
void getMinMax(int& min, int& max, Node* node, int horizDist){
    if(!node)
        return;
    if(min>horizDist)
        min = horizDist;
    else if(max<horizDist)
        max = horizDist;
    getMinMax(min,  max,node->left, horizDist - 1);
    getMinMax(min, max, node->right, horizDist + 1);
}
void printCurrLine(int level, int hd, Node* node){
    if(!node)
        return;
    if(level== hd){
        cout<<node->val<<"->";
    }
    printCurrLine(level, hd-1, node->left);
    printCurrLine(level, hd+1, node->right);

}

void printVertLevel(Node* node){
    int minHd = 0;
    int maxHd = 0;

    getMinMax(minHd, maxHd, node, 0);

    for (int i = minHd; i <= maxHd; i++)
    {
        printCurrLine(i, 0, node);
        cout<<"\n";
    }
    
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//topView

void printTopView(Node* node){
    if(!node)
        return;
    // there should be only one element for each horix dist
    map<int, int> m; // horizDist, element
    queue<pair<Node*, int> > q; // node, horizDist
    q.push({node, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        if(m.find(p.second) == m.end())
            m[p.second] = p.first->val;
        
        if(p.first->left)
            q.push(make_pair(p.first->left, p.second - 1));

        if(p.first->right)
            q.push(make_pair(p.first->right, p.second + 1));
    }

    for (auto &&p : m)
    {
        cout<<p.second<<" | ";
    }
    
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Node* insert(Node* root, int key){
    if(root == NULL)
        return newNode(key);

    if(key < root->val){
        root->left = insert(root->left, key);
    }
    else (key > root->val){
        root->right = insert(root->right, key);
    }
    return root;
}

Node* minValNode(Node* root){
    Node* minNode = root;
    while(minNode && minNode->left)
        minNode = minNode->left;

    return minNode;    
}

Node* deleteNode(Node* root, int key){
    if(root == NULL)
        return NULL;
    if(key<root->val)
        root->left = deleteNode(root->left, key);
    else if(key > root->val)
        root->right = deleteNode(root->right, key);
    else{// root has the key of node to delete
        if(root->left == NULL  && root->right == NULL)
            return NULL;
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // if both childs valid
        Node* temp = minValNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Driver program to test above functions
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	cout << "Vertical order traversal is: \n";
	printVerticalView(root);
    cout<<endl;
	cout << "minMax Vertical order traversal is: \n";
    printVertLevel(root);
	cout << "top view is: \n";
    printTopView(root);
	return 0;
}