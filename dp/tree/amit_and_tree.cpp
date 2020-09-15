#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<pair<int,int>>> g ;
vector<int> a ;
const int N = 1e5 + 10 ;
int cnt[N] ;
int ans = 0 ;

void dfs(int start , int parent = -1){
	cnt[start] = 1 ;
	for(auto i : g[start]){
		if(i.first == parent) continue ;
		dfs(i.first , start) ;
		cnt[start] += cnt[i.first] ;
	}
}

void solve(int start , int parent = -1 , int d = 0){
	if(d > a[start]){
		ans += cnt[start] ;
		return ;
	}
	for(auto i : g[start]){
		if(i.first == parent) continue ;
		solve(i.first , start , max(0LL , d + i.second)) ;
	}
}

int32_t main(){
	int n ;
	cin >> n ;
	g.resize(n) ;
	a.resize(n) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s , c;
		cin >> f >> s >> c ;
		f-- , s-- ;
		g[f].push_back({s,c}) ;
		g[s].push_back({f,c}) ;
	}
	dfs(0) ;
	solve(0) ;
	cout << ans ;
	return 0 ;
}

