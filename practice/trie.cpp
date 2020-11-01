#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct Node{
	bool isLeaf ;
	Node* child[26] ;

	Node() : isLeaf(false) {
		for(int i = 0 ; i < 26 ; i++) child[i] = NULL ;
	}
} ;

struct Trie{
	Node* root ;
	Trie(){
		root = new Node ;
	}

	void insert(string& s){
		Node *cur = root ;
		for(auto i : s){
			if(!cur->child[i-'a']){
				cur->child[i-'a'] = new Node() ;
			}
			cur = cur->child[i-'a'] ;
		}
		cur->isLeaf = true ;
	}

	bool search(string &s){
		Node *cur = root ;
		for(auto i : s){
			if(!cur->child[i-'a']) return false ;
			cur = cur->child[i-'a'] ;
		}
		return cur->isLeaf ;
	}
} ;

int32_t main(){
	int x ;
	cin >> x ;
	Trie t ;
	while(x--){
		string s ; cin >> s ;
		t.insert(s) ;
	}
	int y ; cin >> y ;
	while(y--){
		string s ;
		cin >> s ;
		cout << t.search(s) << '\n' ;
	}
	return 0 ;
}

