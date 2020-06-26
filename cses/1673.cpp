#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<pair<int,int>> g ;
vector<int> reach , visited , d ;

bool dfs(int start , int n){
	if(start == n - 1) return reach[start] = true ;
	visited[start] = 1 ;
	bool ans = false ;
	for(auto i : g[start]){
		if(!visited[i]){
			ans |= dfs(i,n) ;
		}
	}
	return reach[start] = ans ;
}

int ff(int start , int n , int cost = 0){
	if(start == n-1){
		return cost ;
	}
	visited[
int32_t main(){
	int n , m ;
	cin >> n >> m ;
	g.resize(n) ;
	reach.resize(n) ;
	visited.resize(n) ;
	d.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s , c ;
		cin >> f >> s >> c ; 
		f-- , s-- ;
		g[f].push_back({s,c}) ;
	}
	dfs(0,n) ;
	visited.clear() ;
	visited.resize(n) ;
	cout << ff(0,n) ;
	return 0 ;
}

