#include <bits/stdc++.h>
using namespace std ;

#define int long long
vector<vector<int>> g; // adjacency list of graph
vector<vector<pair<int,int>>> vg ;
vector<bool> visited;
vector<int> tin, low;
const int N = 3e5 + 10 ;
map<int,int> mp[N] ;
int timer;

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
} dsu ;


void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                mp[v][to] = 1 ;
				mp[to][v] = 1 ;
			}
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void dfs2(int start , vector<int>&mxd , int d = 0){
	visited[start] = 1 ;
	mxd[start] = d ;
	for(auto i : vg[start]){
		if(!visited[i.first]){
			dfs2(i.first, mxd, d + i.second) ;
		}
	}
}

pair<int,int> diameter(int start , int n){
	vector<int> mxd(n) ;
	visited.clear() ;
	visited.resize(n) ;
	dfs2(start,mxd) ;
	int mx = *max_element(mxd.begin() , mxd.end()) ;
	for(int i = 0 ; i < n ; i++){
		if(mxd[i] == mx) return {i , mx} ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	g.resize(n) ;
	vg.resize(n) ;
	DSU dsu(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	find_bridges(n) ;
	for(int i = 0; i < n;  i++){
		for(auto j : g[i]){
			if(mp[i].count(j)) continue ;
			dsu.merge(i,j) ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(auto j : g[i]){
			if(dsu.gp(i) != dsu.gp(j)){
				vg[dsu.gp(i)].push_back({dsu.gp(j),1}) ;
			}
		}
	}
	auto node = diameter(dsu.gp(0),n) ;
	auto ans = diameter(node.first, n) ;
	cout << ans.second ;
	return 0 ;
}



