#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;

vector<vector<int>> g ;
int a[N] ;
int sub[N] ;
int ms[N] ;
int ans = 0 ;

void dfs(int start , int parent = -1){
	sub[start] = a[start] ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		dfs(i , start) ;
		sub[start] += sub[i] ;
	}
}

void solve(int start , int parent = -1){
	priority_queue<int , vector<int> , greater<int>> pq ;
	ms[start] = sub[start] ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		solve(i , start) ;
		pq.push(ms[i]) ;
		ms[start] = max(ms[start] , ms[i]) ;
		if(pq.size() > 2) pq.pop() ;
	}
	if(pq.size() >= 2){
		int x = pq.top() ; pq.pop() ;
		int y = pq.top() ; pq.pop() ;
		ans = max(ans , x + y) ;
	}
}

int32_t main(){
	int n ;
	cin >> n ;
	g.resize(n) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	dfs(0) ;
	solve(0) ;
	cout << ans ;
	return 0 ;
}

