#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g , vg;
vector<vector<int>> mp ;
vector<bool> instack ;
bool dfs(int start , vector<int>& topo , int* visited){
	instack[start] = true ;
	visited[start] = true ;
	bool ok = true ;
	for(auto i : g[start]){
		if(!visited[i]){
			ok &= dfs(i,topo,visited) ;
		} else {
			if(instack[i]) ok = false ;
		}
	}
	instack[start] = false ;
	topo.push_back(start) ;
	return ok ;
}

int32_t main(){
	int tc ;
	cin >> tc ;
	while(tc--){
		int n , m ;
		cin >> n >> m ;
		g.clear() ; vg.clear() ; instack.clear() , mp.clear() ;
		g.resize(n) ; vg.resize(n) ; instack.resize(n) , mp.resize(n) ;
		for(int i = 0 ; i < m ; i++){
			int t , f , s ;
			cin >> t >> f >> s ;
			f-- , s-- ;
			if(t) {
				g[f].push_back(s) ;
			}
			else {
				mp[f].push_back(s) ;
				mp[s].push_back(f) ;
			}
		}
		int visited[n] = {} ;
		vector<int> topo ;
		bool found = true ;
		for(int i = 0 ; i < n ; i++){
			if(!visited[i]) {
				found &= dfs(i,topo,visited) ;
			}
		}
		if(!found){
			cout << "NO\n" ;
			continue ;
		}
		reverse(topo.begin() , topo.end()) ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) a[topo[i]] = i ;
		cout << "YES\n" ;
		for(int i = 0 ; i < n ; i++){
			for(auto j : mp[i]){
				if(a[i] < a[j]) cout << i + 1 << " " << j + 1 << '\n' ;
			}
			for(auto j : g[i]) cout << i + 1 << " " << j + 1 << '\n' ;
	
		}
	}
	return 0 ;
}
