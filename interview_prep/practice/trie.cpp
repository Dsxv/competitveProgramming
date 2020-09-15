#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct Node{
	Node* val[26] ;
	bool isend ;
	Node(){
		isend = false ;
		for(int i = 0 ; i < 26 ; i++) val[i] = NULL ;
	}
} ;

struct Trie{
	Node *root ;

	Trie(){
		root = new Node ;
	}

	void insert(string& s){
		Node* cur = root ;
		for(auto i : s){
				if(cur->val[i-'a'] == NULL){
					cur->val[i-'a'] = new Node ;
				}
				cur = cur->val[i-'a'] ;
		}
		cur->isend = true ;
	}

	void printUtil(Node* cur, string s = ""){
		if(!cur) return ;
		if(cur->isend){
			cout << s << '\n' ;
		}
		for(int i = 0 ; i < 26 ; i++){
			printUtil(cur->val[i] , s + (char)(i + 'a')) ;
		}
	}

	void print(){
		Node *cur = root ;
		printUtil(cur) ;
	}
} ;

int32_t main(){
	Trie trie ;
	int n;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		string s ;
		cin >> s ;
		trie.insert(s) ;
	}
	trie.print() ;
	return 0 ;
}

