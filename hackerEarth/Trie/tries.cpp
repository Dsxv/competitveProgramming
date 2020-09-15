#include <bits/stdc++.h>
using namespace std ;

#define int long long
vector<vector<int>> Trie ;
vector<int> val ;

// the cur block represents what part of string is completed
// if "abc" is completed now we are at a block whose address
// is stored in "c" 

void insert(string &s){
	int cur = 0 ;
	for(auto i : s){
		if(Trie[cur][i-'a'] == 0){
			Trie[cur][i-'a'] = Trie.size() ;
			Trie.push_back(vector<int>(26)) ;
		}
		cur = Trie[cur][i-'a'] ;
		val[cur]++ ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n; 
	cin >> n ;
	val.resize(n+10) ;
	Trie.push_back(vector<int>(26)) ;
	while(n--){
		string s , t ;
		cin >> s >> t ;
		if(s == "add"){
			insert(t) ;
		} else {
			int cur = 0 ;
			int ans = 0 ;
			for(auto i : t){
				cur = Trie[cur][i-'a'] ;
				if(!cur){
					ans = 0 ;
					break ;
				}
				assert(cur < val.size()) ;
				ans = val[cur] ;
			}
			cout << ans << '\n' ;
		}
	}
	return 0 ;
}
