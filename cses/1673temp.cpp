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
} dsu(3000) ;

const int INF = 1e15 ;
struct edge{
	int a , b , c ;
} ;
vector<edge> g ;
vector<vector<int>> gg , ggcomp;

void dfs(int start , vector<int>& v , int* visited){
	if(visited[start]) return ;
	visited[start] = 1 ;
	for(auto i : gg[start]){
		dfs(i,v,visited) ;
	}
	v.push_back(start) ;
}

void dfs2(int start , vector<int>& v , int* visited){
	if(visited[start]) return ;
	visited[start] = 1 ;
	for(auto i : ggcomp[start]){
		dfs2(i,v,visited) ;
	}
	v.push_back(start) ;
}

pair<vector<int>,vector<int>> solve(int start , int n){
	vector<int> d(n,INF) ;
	vector<int> p(n,-1) ;
	p[start] = start ;
	d[start] = 0 ;
	int x ;
	for(int i = 0 ; i < n ; i++){
		x = -1 ;
		for(auto j : g){
			if(d[j.a] < INF && (dsu.gp(n-1) == dsu.gp(j.a)) ) {
				if(d[j.b] > d[j.a] + j.c){
					d[j.b] = max(-INF , d[j.a] + j.c) ;
					p[j.b] = j.a ;
					x = j.b ;
				}
			}
		}
	}
	// x != -1 means last run me bhi kuch update hua hai , gadbad
	if(~x){
		cout << -1 ;
		exit(0) ;
	} else {
		return {d,p} ;
	}
}

int32_t main(){
	int n , m  ;
	cin >> n >> m ;
	g.resize(m) ;
	gg.resize(n) ;
	ggcomp.resize(n) ;

	for(int i = 0 ; i < m ; i++){
		cin >> g[i].a >> g[i].b >> g[i].c ;
		g[i].a-- , g[i].b-- ;
		gg[g[i].a].push_back(g[i].b) ;
		ggcomp[g[i].b].push_back(g[i].a) ;
		g[i].c *= -1 ;
	}
	gg[n-1].push_back(0) ;
	ggcomp[0].push_back(n-1) ;
	vector<int> v;
	int visited[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]) dfs(i,v,visited) ;
	}
	for(int i = 0 ; i < n ; i++) visited[i] = 0 ;
	vector<vector<int>> comp ;
	while(v.size()){
		if(!visited[v.back()]){
			vector<int> temp ;
			dfs2(v.back() , temp , visited) ;
			comp.push_back(temp) ;
		}
		v.pop_back() ;
	}
	for(auto i : comp){
		for(auto j : i) dsu.merge(i.back() , j) ;
	}
	auto [d,p] = solve(0,n) ;
	cout << d.back()*-1 ;
	return 0 ;
}

