#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;
vector<int> node ;

int dfs(int start , int val , int parent = -1){
	node[start] = val ;
	int count = 1 ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		dfs(i , val + count , start) ;
		count++ ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ; cin >> n ;
		g.clear(); 
		g.resize(n) ;
		node.clear() ;
		node.resize(n) ;
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		}
		dfs(0,100) ;
		for(auto i : node) cout << i << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

