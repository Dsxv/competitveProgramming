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

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	g.resize(n) ;
	DSU dsu(n) ;
	int start = -1 , end = -1 ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
		if(dsu.merge(f,s)) {
			start = f ; 
			end = s ;
		}
	}
	if(~start){
		queue<int> q ;
		int parent[n] ;
		memset(parent , -1 , sizeof(parent)) ;
		parent[start] = start ;
		q.push(start) ;
		while(q.size()) {
			int x = q.front() ;
			if(x == end){
				break ;
			}
			q.pop() ;
			for(auto i : g[x]){
				if(~parent[i]) continue ;
				if(i == end && x == start) continue ;
				q.push(i) ;
				parent[i] = x ;
			}
		}
		vector<int> ans ;
		ans.push_back(start) ;
		while( end != start) {
			ans.push_back(end) ;
			end = parent[end] ;
		}
		ans.push_back(start) ;
		cout << ans.size() << '\n' ;
		for(auto i : ans) cout << i + 1 << " " ;
	} else {
		cout << "IMPOSSIBLE" ;
	}
	return 0 ;
}


