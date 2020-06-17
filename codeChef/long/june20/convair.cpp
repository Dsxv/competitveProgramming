#include <bits/stdc++.h>
using namespace std ;

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
		return true ;
	}
} ;

vector<map<int,int>> g ;
vector<pair<int,int>> ng ;
int ans = 0 ;
void solve(DSU &dsu , vector<pair<int,int>>& comp , vector<pair<int,int>>& extra_edges , int start , int & l , map<pair<int,int>,int>& ign){
	for(auto i : comp){
		if(l < extra_edges.size()){
			int f = extra_edges[l].first , s = extra_edges[l].second ;
			ng.push_back({f,i.first}) ;
			ng.push_back({s,i.second}) ;
			ign[extra_edges[l]]++ ;
			l++ ;
		} else {
			if(dsu.gp(start) != dsu.gp(i.first)) {
				ng.push_back({start , dsu.gp(i.first)}) ;
				ans += 2 ;
			}
			if(dsu.gp(i.first) != dsu.gp(i.second)){
				ng.push_back({start , dsu.gp(i.second)}) ;
				ans += 2 ;
			}
		}
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		DSU dsu(n) ;
		g.clear() ;
		g.resize(n) ;
		ng.clear() ;
		ans = 0 ;
		vector<pair<int,int>> v ;
		for(int i = 0 ; i < m ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			v.push_back({f,s}) ;
			if(dsu.gp(f) != dsu.gp(s)){	
				dsu.merge(f,s) ;
				g[f][s] = 1 ;
			}
		}
		for(int i = 0 ; i < n ; i++){
			dsu.parent[i] = dsu.gp(i) ;
		}
		map<int,vector<pair<int,int>>> extra_parents;
		for(auto i : v){
			if(g[i.first][i.second]){ // would be 1 when accessed first time
				g[i.first][i.second]-- ; // set it to 0 for later accesses
			} else {
				extra_parents[dsu.gp(i.first)].push_back(i) ;
			}
		}
		vector<pair<int,int>> comp ;
		vector<pair<int,int>> free_node ;
		int free_nd = -1 ;
		int visited[n] = {} ;
		map<pair<int,int> , int> ign ;
		for(int i = 0 ; i < n ; i++){
			if(visited[dsu.gp(i)] || extra_parents.count(dsu.gp(i))) continue ;
			visited[dsu.gp(i)] = 1 ;
			if(g[dsu.gp(i)].size()) {
				int f = dsu.gp(i) , s = g[dsu.gp(i)].begin()->first ;
				ign[{f,s}] = 1 ;
				comp.push_back({f , s}) ;
			} else {
				if(free_nd == -1) free_nd = i ;
				else {
					free_node.push_back({free_nd , i}) ;
					free_nd = -1 ;
				}
			}
		}
		vector<pair<int,int>> extra_edges , header;
		int start ;
		if(extra_parents.size()) {
			start = extra_parents.begin()->first ;
		} else if(comp.size()) {
			start = comp.begin()->first ;
		} else if(free_node.size()) {
			start = free_node.begin()->first ;
		} else {
			assert(free_nd != -1) ;
			start = free_nd ;
		}
		for(auto i : extra_parents){
			for(auto j : i.second){
				extra_edges.push_back(j) ;
			}
			if(i.first != start) {
				int f = dsu.gp(i.first) , s = g[dsu.gp(i.first)].begin()->first ;
				header.push_back({f,s}) ;
				ign[{f,s}]++ ;
			}
		}
		int l = 0 ;
		solve(dsu, header , extra_edges , start , l , ign) ;
		solve(dsu , comp , extra_edges , start , l , ign) ;
		solve(dsu , free_node , extra_edges , start , l , ign) ;
		if(~free_nd) {
			if(dsu.gp(free_nd) != dsu.gp(start)) {
				ng.push_back({free_nd , start}) ;
				ans += 2 ;
			}
		}
		while(l < extra_edges.size()){
			ng.push_back(extra_edges[l]) ;
			ign[extra_edges[l]]++ ;
			l++ ;
		}
		for(auto i : v){
			if(ign.count(i)) { 
				ign[i]-- ;
				if(ign[i] == 0) ign.erase(i) ;
				continue ;
			}
			ng.push_back(i) ;
		}
		cout << ans << " " << ng.size() << '\n' ;
		for(auto i : ng) cout << i.first + 1 << " " << i.second + 1 << '\n' ;
	}
	return 0 ;
}
