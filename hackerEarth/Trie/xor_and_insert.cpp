#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> Trie ;
const int N = 1e6 + 10 ;
int val[N] ;
// first is 0 , second is 1
void insert(int x){
	int cur = 0 ;
	for(int i = 30 ; i >= 0 ; i--){
		bool id = x&(1LL<<i) ;
		if(Trie[cur][id] == 0){
			Trie[cur][id] = Trie.size() ;
			Trie.push_back(vector<int>(2)) ;
		}
		cur = Trie[cur][id] ;
	}
}

void print_all(int cur = 0 , int x = 0 , int i = 30){
	if(i == -1){
		cout << x << '\n' ;
	}
	if(Trie[cur][0]) print_all(Trie[cur][0] , x , i - 1) ;
	if(Trie[cur][1]) print_all(Trie[cur][1] , x | (1LL<<i) , i - 1) ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int q ;
	cin >> q ;
	Trie.push_back(vector<int>(2)) ;
	insert(0) ;
	int cxor = 0 ;
	while(q--){
		int t ;
		cin >> t ;
		if(t == 1){
			int x ; cin >> x ;
			insert(x^cxor) ;
		} else if(t == 2){
			int x ; cin >> x ;
			cxor ^= x ;
		} else {
			int cur = 0 ;
			int ans = 0 ;
			for(int i = 30 ; i >= 0 ; i--){
				bool id = (1LL<<i)&cxor ;
				if(Trie[cur][id] == 0){
					id = !id ;
				}
				assert(Trie[cur][id]) ;
				cur = Trie[cur][id] ;
				ans |= ((1&id)<<i) ;
			}
			cout << (ans^cxor) << '\n' ;
		}
	}
		
	return 0 ;
}

