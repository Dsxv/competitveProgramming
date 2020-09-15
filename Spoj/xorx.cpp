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
		for(int i = 32 ; i >= 0 ; i--){
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

	void print_all(int cur = 0 , int x = 0 , int i = 31){
		if(i == -1){
			cout << x << '\n' ;
			return ;
		}
		if(t[cur][0]) print_all(t[cur][0] , x , i - 1) ;
		if(t[cur][1]) print_all(t[cur][1] , x | (1LL<<i) , i - 1) ;
	}

	int max_xor(int x){
		int cur = 0 ;
		int ans = 0 ;
		for(int i = 32 ; i >= 0 ; i--){
			bool id = (1LL<<i) & x ;
			id ^= 1 ; // remove this for min_xor
			if(!t[cur][id]) id ^= 1;
			if(id) ans |= (1LL<<i) ;
			cur = t[cur][id] ;
		}
		return ans ;
	}
};

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , x , xr = 0;
		cin >> n >> x ;
		int mx = 0 ;
		int mxv = 0 ;
		Trie trie ;
		for(int i = 0 ; i < n ; i++){
			int a ;
			cin >> a ;
			xr ^= a ;
			int val = trie.max_xor(xr^x) ;
			if(i && mxv < (xr^x^val)){
				mx = val ; 
				mxv = mx^xr^x ;
			}
			if(mxv < (xr^x)){
				mx = xr ;
				mxv = xr^x ;
			}
			trie.insert(xr) ;
		}
		cout << mx << '\n' ;
	}
	return 0 ;
}


