#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;
vector<int> p ;
vector<int> h ;
bool ok ;

pair<int,int> dfs(int start , int parent = -1) {
	int hsum = 0 , psum = 0 ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		auto x = dfs(i , start) ;
		hsum += x.first ;
		psum += x.second ;
	}
	if(((p[start] + psum)%2)^(h[start] + (int)1e9 )%2){
		ok = false ;
	}
	if(h[start] < (hsum - p[start])){
		ok = false ;
	}
	if(abs(h[start]) > (p[start] + psum)){
		ok = false ;
	}
	return {h[start] , p[start] + psum} ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		ok = true ;
		g.clear() ; p.clear() ; h .clear() ;
		g.resize(n) ; p.resize(n) ; h.resize(n) ;
		for(int i = 0 ; i < n ; i++){
			cin >> p[i] ;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> h[i] ;
		}
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		}
		dfs(0) ;
		cout << (ok ? "YES" : "NO") << '\n' ;
	}
	return 0 ;
}

