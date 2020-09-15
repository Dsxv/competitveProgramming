// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
   		Node* root = constructTree(post, n);
		//printInorder(root);
        //printf("\n");
	}
	return 0;
}

Node* solve(int* post , int * nextMin , int l , int r){
    if(l > r) {
        return NULL ;
    }
    int cur = l ;
    Node *root = new Node(post[cur]) ;
    if(l == r){
        return root ;
    }
    int leftRoot = nextMin[cur] ;
    root->left = solve(post , nextMin , leftRoot , r) ;
    root->right = solve(post , nextMin , l + 1 , leftRoot - 1) ;
    return root ;
}

Node *constructTree (int post[], int size)
{
    reverse(post , post + size) ;
    int nextMin[size] ;
	cout << "here" ;
	stack<int> st ;
	for(int i = 0 ; i < size ; i++){
		while(st.size() && post[i] < post[st.top()]){
			post[st.top()] = i ;
			st.pop() ;
		}
		st.push(i) ;
	}
	while(st.size()){
		post[st.top()] = st.top() + 1 ;
		st.pop() ;
	}
    //for(int i = 0 ; i < size ; i++) cout << post[i] << " " ;
    //for(int i = 0 ; i < size ; i++) cout << nextMin[i] << " " ;
    // return solve(post , nextMin , 0 , size - 1) ;
    return NULL ;
}
