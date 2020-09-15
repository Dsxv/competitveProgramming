#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 , mod = 1e9 + 7 ;
int dp[N][4] ;
vector<vector<int>> g ;

int dfs(int start , int cx , int parent = -1 ){
	if(~dp[start][cx]) return dp[start][cx] ;
	int ans = 0 ;
	int ch = 0 ;
	for(int i = 0 ; i < 4 ; i++){
		int val = 1 ;
		for(auto j : g[start]){
			if(j == parent) continue ;
			ch++ ;
			val = (val * dfs(j , cx^i , start)) % mod ;
		}
		ans = (ans + val) % mod;
	}
	if(!ch){
		ans = 1 ;
	}
	return dp[start][cx] = ans ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < 4 ; j++){
				dp[i][j] = -1 ;
			}
		}
		g.clear() ;
		g.resize(n) ;
		for(int i = 0 ; i < n - 2 ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		}
		int ans = 0 ;
		for(int i = 0 ; i < 4 ; i++){
			ans = (ans + dfs(0 , i)) % mod ;
		}
		cout << ans << '\n';
	}
	return 0 ;
}


