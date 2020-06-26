#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	g.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	int parent[n] = {} ;
	memset(parent , -1 , sizeof(parent)) ;
	queue<int> q ;
	q.push(0) ;
	parent[0] = 0 ;
	bool found = false ;
	while(q.size()) {
		int x = q.front() ;
		q.pop() ;
		if(x == n-1){
			found = true ;
		}
		for(auto i : g[x]){
			if(~parent[i]) continue ;
			q.push(i) ;
			parent[i] = x ;
		}
	}
	if(found){
		vector<int> ans ;
		int cur = n - 1 ;
		while(cur != parent[cur]) {
			ans.push_back(cur) ;
			cur = parent[cur] ;
		}
		ans.push_back(0) ;
		reverse(ans.begin()  , ans.end()) ;
		cout << ans.size() << '\n' ;
		for(auto i : ans) cout << i + 1 << " " ;
	} else {
		cout << "IMPOSSIBLE" ;
	}
	return 0 ;	
}

