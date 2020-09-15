#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct Trie{
	vector<vector<int>> t ;
	vector<int> val ;
	Trie(){
		t.push_back(vector<int>(2)) ;
		val.push_back(0) ;
	}
	void insert(int x){
		int cur = 0 ;
		for(int i = 30 ; i >= 0 ; i--){
			bool id = (1LL<<i) & x ;
			if(!t[cur][id]){
				t[cur][id] = t.size() ;
				t.push_back(vector<int>(2)) ;
				val.push_back(0) ;
			}
			cur = t[cur][id] ;
			val[cur]++ ;
		}
	}

	void print_all(int cur = 0 , int x = 0 , int i = 30){
		if(i == -1){
			cout << x << '\n' ;
			return ;
		}
		if(t[cur][0]) print_all(t[cur][0] , x , i - 1) ;
		if(t[cur][1]) print_all(t[cur][1] , x | (1LL<<i) , i - 1) ;
	}

	int count_mxor(int x , int k){
		int ans = 0 ;
		int cur = 0 ;
		for(int i = 30 ; i >= 0 ; i--){
			bool a = (1LL<<i)&x ;
			bool b = (1LL<<i)&k ;
			if(b){
				ans += val[t[cur][a]] ; // where a there 0
				cur = t[cur][!a] ; // same side might give ans later
			} else {
				cur = t[cur][a] ; // b is 0 so have to go where also 0
			}
			if(!cur) break ;
		}
		return ans ;
	}
};

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		Trie trie ;
		int n , k ;
		cin >> n >> k ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int cur = 0 ;
		trie.insert(cur) ;
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			cur ^= a[i] ;
			ans += trie.count_mxor(cur,k) ;
			trie.insert(cur) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


