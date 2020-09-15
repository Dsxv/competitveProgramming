#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int INF = 1e18 ;
vector<vector<int>> g ;
vector<bool> visited ;
vector<int> cost ;
vector<int> ans ;
int dfs(int*a , int start){
	if(visited[start]){
		return cost[start] ;
	}
	visited[start] = true ;
	int val = 0;
	for(auto i : g[start]){
		val = max(val , dfs(a , i)) ;
	}
	cost[start] = a[start] + val ;
	ans.push_back(start) ;
	return cost[start] ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] , b[n] ;
	g.clear() ; visited.clear() ; cost.clear() ;
	g.resize(n) ; visited.resize(n) ; cost.resize(n) ;
	ans.clear() ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++) cin >> b[i] ;
	vector<int> indeg(n) ;
	for(int i = 0 ; i < n ; i++){
		if(b[i] != -1){
			g[b[i]-1].push_back(i) ;
			indeg[i]++ ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(!indeg[i]){
			dfs(a , i) ;
		}
	}
	cout << accumulate(cost.begin() , cost.end() , 0LL) << '\n' ;
	for(auto i :ans) cout << i+1 << " " ;
	return 0 ;
}

