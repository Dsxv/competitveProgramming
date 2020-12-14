#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;
bool even[N] ;
int ans = 0 ;
void solve(Node *root , int d = 0){
	if(!root) return ;
	if(d >= k) ans += even[d-k]*(root->data) ;
	even[d] = root->data % 2 == 0;
	solve(root->left , d + 1) ;
	solve(root->right , d + 1) ;
	even[d] = 0 ;
}

int32_t main(){
	
	return 0 ;
}

