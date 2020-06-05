#include <bits/stdc++.h>
using namespace std ;

const int N = 5e4 + 10  , K = 501;
int n , k ;
int dp2[N][K] ;
int dp1[N][K] ;
// dp1[u][k] = dp2[u][k] + dp1[p][k-1] - dp2[u][k-2] ;
vector<int> g[N] ;

void dfs(int start , int parent = -1){
	dp2[start][0] = 1 ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		dfs(i,start) ;
		for(int j = 1 ; j <= k ; j ++){
			dp2[start][j] += dp2[i][j-1] ;
		}
	}
}

void dfs2(int start , int parent = -1){
	if(parent == -1){
		for(int j = 0 ; j <= k ; j++){
			dp1[start][j] = dp2[start][j] ;
		}
	} else {
		for(int j = 0 ; j <= k ; j++){
			dp1[start][j] = dp2[start][j] ;
			if(j >= 1) dp1[start][j] += dp1[parent][j-1] ;
			if(j > 1) dp1[start][j] -= dp2[start][j-2] ;
		}
	}
	for(auto i : g[start]){
		if(i == parent) continue ;
		dfs2(i,start) ;
	}
}

int32_t main(){
	cin >> n >> k ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	dfs(0) ;
	dfs2(0) ;
	long long ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		ans += dp1[i][k] ;
	}
	cout << ans / 2 ;
	return 0 ;
}

