#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g , gcomp;

void dfs(int start , vector<int>& v , int* visited){
	if(visited[start]) return ;
	visited[start] = 1 ;
	for(auto i : g[start]){
		dfs(i,v,visited) ;
	}
	v.push_back(start) ;
}

void dfs2(int start , vector<int>& v , int* visited){
	if(visited[start]) return ;
	visited[start] = 1 ;
	for(auto i : gcomp[start]){
		dfs2(i,v,visited) ;
	}
	v.push_back(start) ;
}

int32_t main(){
	int n ;
	cin >> n ;
	g.resize(n) ;
	gcomp.resize(n) ;
	int cost[n] ;
	for(int i = 0 ; i < n ; i++) cin >> cost[i] ;
	int m ; cin >> m ;
	for(int i = 0 ; i < m ; i++){
		int f , s  ;
		cin >> f >> s;
		f-- , s-- ;
		g[f].push_back(s) ;
		gcomp[s].push_back(f) ;
	}
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
	int way = 1 , ans = 0 ;
	for(auto i : comp){
		int mn = INT_MAX; 
		for(auto j : i) mn = min(mn , cost[j]) ;
		int count = 0 ;
		for(auto j : i) count += mn == cost[j] ;
		way = (way*count) % ((int) 1e9 + 7) ;
		ans += mn ;
	}
	cout << ans << " " << way << '\n' ;
	return 0 ;
}


