#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;
const int N = 1e5 + 10 ;
int visited[N]  ;

bool dfs(int start , int col = 0){
	visited[start] = col ;
	bool ok = true ;
	for(auto i : g[start]){
		if(~visited[i]){
			if(col == visited[i]) ok = false ;
		} else {
			ok &= dfs(i , !col) ;
		}
	}
	return ok ;
}


int32_t main(){
	int n , m ;
	cin >> n >> m ;
	g.resize(n) ;
	memset(visited , -1 , sizeof(visited)) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	bool ans = true ;
	for(int i = 0 ; i < n ; i++){
		if(~visited[i]) continue ;
		ans &= dfs(i) ;
	}
	if(ans) {
		for(int i = 0 ; i < n ; i++) cout << visited[i] + 1 << " " ;
	} else {
		cout << "IMPOSSIBLE" ;
	}
	
	return 0 ;
}

