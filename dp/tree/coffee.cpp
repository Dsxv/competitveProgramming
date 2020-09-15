#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10;
vector<int> g[N] ;
int dp[N][11] ;

int ans ;
int n , k ;

void solve(int start , int parent = -1){
	for(auto i : g[start]){
		if(i == parent) continue ;
		solve(i , start) ;
		for(int j = 10 ; j > 0 ; j--){
			dp[i][j] = dp[i][j-1] ;
			dp[start][j] += dp[i][j] ;
		}
		dp[i][0] = 0 ;
	}
	int cnt = 0 ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		for(int j = 0 ; j <= k ; j++){
			cnt += dp[i][j]*(dp[start][k-j] - dp[i][k-j]) ;
		}
	}
	dp[start][0]++ ;
	ans += cnt / 2 ;
	ans += dp[start][k] ;
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
	solve(0) ;
	cout << ans ;	
	return 0 ;
}

