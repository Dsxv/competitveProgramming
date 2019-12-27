#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 3e5 + 10 ; // change this according to n

struct DSU{
	int n = MAXN  ;
	int parent[MAXN] , rank[MAXN] ;
	DSU(){
		for(int i = 0 ; i < n ; i++) {
			parent[i] = i ;
			rank[i] = 1 ;
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
		if(rank[a] < rank[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		rank[a] += rank[b] ;
		return true ;
	}
} dsu ;

vector<int> G[MAXN] ;

bool check(set<int>& s) {
	map<int,int> mp ;
	for(auto i : G[0]){
		mp[dsu.gp(i)]++ ;
	}
	for(auto i : s){
		if(dsu.rank[dsu.gp(i)] <= mp[dsu.gp(i)]){
			return 0;
		}
	}
	return 1 ;
}


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m , k ;
	cin >> n >> m >> k;
	int max_deg = n - 1 ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
		if(f == 0 || s == 0) max_deg-- ;
	}
	
	if(max_deg < k) {
		cout << "impossible" ;
		return 0 ;
	}
	for(int i = 0 ; i < n ; i++) sort(G[i].begin(),G[i].end()) ;
	set<int> s ;
	for(int i = 1 ; i < n ; i++){
		map<int,int> mp ;
		for(auto j : G[i]){
			if(j == 0) continue ;
			if(j >= i) break ;
			mp[dsu.gp(j)]++ ;
		}
		vector<int> v ;
		for(auto j : s){
			if(dsu.rank[dsu.gp(j)] > mp[dsu.gp(j)]){
				v.push_back(j) ;
				dsu.merge(j,i) ;
			}
		}
		for(auto j : v) s.erase(j) ;
		s.insert(i) ;
	}
	// now confirming all comps are connected to 1 with at least 1 edge
	if(s.size() <= k && check(s)) cout << "possible" ;
	else cout << "impossible" ;
	return 0 ;
}

 
