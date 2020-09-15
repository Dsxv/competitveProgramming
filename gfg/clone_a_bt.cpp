// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};


Node *cloneTree(Node *);

void print(Node* root) {

    cout << root->data << ":" << (root->left?root->left->data:-1) << ":" << (root->right?root->right->data:-1) << endl ;
}



void inorder(Node *root)
{
    if (root == NULL) return;
	inorder(root->left) ;
	cout << root->data << " " ;	
	inorder(root->right) ;
}

void pre(Node *root){
	if(root==NULL) return ;
	cout << root->data << " " ;
	pre(root->left) ; pre(root->right) ;
}

/* Driver program to test size function*/
int main()
{
 	Node* root = new Node(1) ;
 	root->left = new Node(2) ;
 	root->right = new Node(3) ;
	auto x = cloneTree(root) ;
	pre(root) ;
	cout << endl ;
	pre(x) ;
  return 0;
}



Node* cloneTree(Node* tree);
// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

/* The function should clone the passed tree and return 
   root of the cloned tree */
void solve(Node* root){
    if(!root) return ;
    Node *temp = new Node(root->data) ;
    temp->left = root->left ;
    root->left = temp ;
    temp->right = root->right ;
    solve(root->right) ;
    solve(temp->left) ;
}

void setRandom(Node* root){
    if(!root) return ;
    root->left->random = (root->random ? root->random->left : NULL) ;
    setRandom(root->left->left) ;
    setRandom(root->right) ;
}
void unMerge(Node* root){
    if(!root) return ;
    Node* temp = root->left ;
    root->left = temp->left ;
    if(root->right) temp->right = root->right->left ;
	if(temp->left) temp->left = temp->left->left ;
	unMerge(root->left) ;
    unMerge(root->right) ;
}
   
Node* cloneTree(Node* root)
{
  solve(root) ;
  setRandom(root) ;
  Node* newRoot = root->left ;
  unMerge(root) ;
  return newRoot ;
}
