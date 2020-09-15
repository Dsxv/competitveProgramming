#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int dp[N] ;
vector<int> g[N] ;

int solve(int start){
	if(~dp[start]) return dp[start] ;
	dp[start] = 0 ;
	for(auto i : g[start]){
		solve(i) ;
		dp[start] = max(1 + dp[i] , dp[start]) ;
	}
	return dp[start] ;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	memset(dp , -1 , sizeof(dp)) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		ans = max(ans , solve(i)) ;
	}
	cout << ans ;
	return 0 ;
}

