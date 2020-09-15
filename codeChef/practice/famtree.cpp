#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int mn[N] , mx[N] ;
int a[N] ;
vector<vector<int>> g ;
int ans  ;

void dfs(int start){
	for(auto i : g[start]){
		dfs(i) ;
		mx[start] = max(mx[start] , mx[i]) ;
		mn[start] = min(mn[start] , mn[i]) ;
	}
	ans = max({ ans , abs(a[start] - mx[start]) , abs(a[start] - mn[start]) }) ; 
}

int32_t main(){
	int n; 
	cin >> n ;
	g.resize(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		mn[i] = mx[i] = a[i] ; 
	}
	int start = 0 ;
	for(int i = 0 ; i < n ; i++){
		int p ; cin >> p ;
		if(p == -1) {
			start = i ; continue ;
		}
		p-- ;
		g[p].push_back(i) ;
	}
	dfs(start) ;
	cout << ans ;
	return 0 ;
}

