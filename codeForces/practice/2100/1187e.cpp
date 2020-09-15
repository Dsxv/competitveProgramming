#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e5 + 10 ;
vector<vector<int>> g ;

int val[N]  , cnt[N] ;
int ans[N] ;
int n ;

void dfs(int start , int parent = -1){
	cnt[start] = 1 ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		dfs(i , start) ;
		val[start] += val[i] ;
		cnt[start] += cnt[i] ;
	}
	val[start] += cnt[start] ;
}

void solve(int start , int parent = -1){
	if(~parent){
		ans[start] = ans[parent] + n - 2*cnt[start] ;
	} else {
		ans[start] = val[start] ;
	}
	for(auto i : g[start]){
		if(i == parent) continue ;
		solve( i , start) ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	cin >> n; 
	g.resize(n) ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	dfs(0) ;
	solve(0) ;
	cout << *max_element(ans , ans + n) ;
	return 0 ;
}
