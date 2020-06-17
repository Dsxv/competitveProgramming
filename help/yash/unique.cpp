#include <bits/stdc++.h>
using namespace std ;
const int N = 1e6 + 10 ;

vector<int> g[N] ;
vector<int> visited ;

vector<int> ans ;

int solve(int start){
	visited[start] = 1 ;
	int count = 1 ;
	for(auto i : g[start]){
		if(!visited[i]){
			count += solve(i) ;
		}
	}
	return count ;
}

void dfs(int start){
	visited[start] = 1 ;
	for(auto i : g[start]){
		if(!visited[i]){
			dfs(i) ;
		}
	}
	ans.push_back(start) ;
}


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		g[f].push_back(s) ;
	}
	visited.resize(n) ;
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]) {
			dfs(i) ;
		}
	}
	reverse(ans.begin() , ans.end()) ;
	visited.assign(n,0) ;
	if(solve(ans[0]) == n){
		cout << ans[0] ;
	} else {
		cout << -1 ;
	}
	return 0 ;
}

