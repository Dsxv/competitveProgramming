#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ; // change this according to n

struct DSU{
	int parent[N] , vall[N] ;
	DSU(){
		for(int i = 0 ; i < N ; i++) {
			parent[i] = i ;
			vall[i] = 1 ;
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
		if(vall[a] < vall[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		vall[a] += vall[b] ;
		return true ;
	}
} dsu ;

set<int> G[N] ;
vector<int> node ;
//0 , 1 are coloring , 

void ff(int start , int col , int type ,  map<int,int>& visited){
	if(visited.count(start)) return ;
	visited[start] = 1 ;
	node[start] = col ;
	for(auto i : G[start]){
		if(type == 2)
			ff(i,col,type,visited) ;
		else 
			ff(i,!col,type,visited) ;
	}
}


void dfs(int v , int col){
	map<int,int> mp ;
	ff(v,col,col,mp) ;
}

int32_t main(){
	node.resize(N) ;
	int n , q ;
	cin >> n >> q ;
	while(q--){
		int t , u , v;
		cin >> t  >> u >> v ;
		u-- , v-- ;
		if(t == 1){
			if(G[u].count(v)){
				continue ;
			}
			if(dsu.gp(u) != dsu.gp(v)) {
				if(node[u] == 2){
					if(node[v] != 2){
						dfs(v,2) ;
					}
				}
				else if(node[v] == 2){
					if(node[u] != 2){
						dfs(u,2) ;
					}
				}
				else if (node[u] == node[v]){
					if(dsu.vall[dsu.gp(u)] < dsu.vall[dsu.gp(v)]) {
						dfs(u,!node[v]) ;
					} else {
						dfs(v,!node[u]) ;
					}
				}
				dsu.merge(u,v) ;
			} else {
				if(node[u] == node[v]) {
					dfs(u,2) ;
				}
			}
			G[u].insert(v) ;
			G[v].insert(u) ;
		} else {
			if(node[u] == 2 || node[v] == 2){
				cout << "No\n" ;
				continue ;
			}
			if(dsu.gp(u) != dsu.gp(v)){
				cout << "Yes\n" ;
			} else {
				if(node[u] == node[v]) cout << "No\n" ;
				else cout << "Yes\n" ;
			}
		}
	}
	return 0 ;
}


