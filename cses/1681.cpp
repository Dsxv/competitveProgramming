#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;
const int N = 1e5 + 10 , mod = 1e9 + 7 ;
int dp[N] ;
int n , m ;
int solve(int start){
	if(start == n-1){
		return 1 ;
	}
	if(~dp[start]) return dp[start] ;
	int ans = 0 ;
	for(auto i : g[start]){
		ans = (ans + solve(i)) % mod ;
	}
	return dp[start] = ans ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cin >> n >> m ;
	g.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
	}
	cout << solve(0) ;
	return 0 ;
}

