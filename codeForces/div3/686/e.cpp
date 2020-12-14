#include <bits/stdc++.h>
using namespace std ;

#define int long long


struct DSU{
	vector<int> parent , val ;
	int N ;
	DSU(){
		N = 10 ;
	}
	DSU(int n){
		N = n ;
		parent.resize(n) ;
		val.resize(n) ;
		for(int i = 0 ; i < N ; i++) {
			parent[i] = i ;
			val[i] = 1 ;
		}
	}
	int gp(int v){ //get_parent
		if(v == parent[v])
			return v ;
		return parent[v] = gp(parent[v]) ;
	}
	bool merge(int a , int b){
		a = gp(a) , b = gp(b) ;
		if(a == b) return true ;
		if(val[a] < val[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		val[a] += val[b] ;
		return false ;
	}
} ;

vector<vector<int>> g ;
vector<int> parent ;

bool dfs(int start , int dest , int p) {
	parent[start] = p ;
	if(start == dest) return true ;
	for(auto i : g[start]){
		if(i == p) continue ;
		if(dfs(i , dest , start)){
			return true ;
		}
	}
	return false ;
}

int solve(int start , set<int>& nodes , int parent = -1){
	int count = 1 ;
	for(auto i : g[start]){
		if(nodes.count(i) || i == parent) continue ;
		count += solve(i , nodes , start) ;
	}
	return count ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		g = vector<vector<int>>(n) ;
		pair<int,int> cycle(-1,-1) ;
		DSU dsu(n) ;
		for(int i = 0 ; i < n ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
			if(dsu.merge(f,s)){
				cycle = {f,s} ;
			}
		}
		parent = vector<int>(n , -1) ;
		dfs(cycle.first , cycle.second , cycle.second) ;
		set<int> nodes ;
		int cur = cycle.second ;
		while(true){
			nodes.insert(cur) ;
			if(cur == cycle.first) break ;
			cur = parent[cur] ;
		}
		int ans = 0 ;
		for(auto i : nodes){
			int c = solve(i , nodes) ;
			ans += c * (c - 1) / 2 + c * (n - c) ;
		}
		cout << ans << '\n' ;
	}
}


