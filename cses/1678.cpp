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

void bfs(int start , int n){
	int parent[n] ;
	queue<pair<int,int>> q ;
	parent[start] = start ;
	int visited[n] = {} ;
	q.push({start,0}) ;
	while(q.size()){
		auto [cur,d] = q.front() ;
		if(cur == start && d){
			break ;
		}
		q.pop() ;
		for(auto i : g[cur]){
			if(!visited[i]) {
				visited[i] = 1 ;
				parent[i] = cur ;
				q.push({i,d+1}) ;
			}
		}
	}
	int cur = start ;
	vector<int> ans = {cur} ;
	cur = parent[cur] ;
	while(cur != start) {
		ans.push_back(cur) ;
		cur = parent[cur] ;
	}
	ans.push_back(cur) ;
	cout << ans.size() << endl ;
	reverse(ans.begin() , ans.end()) ;
	for(auto i : ans) cout << i + 1 << " " ;
}

int32_t main(){
	int n , m;
	cin >> n >> m;
	g.resize(n) ;
	gcomp.resize(n) ;
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
	for(auto i : comp){
		if(i.size() > 1){
			bfs(i.back(), n) ;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" ;
	return 0 ;
}


